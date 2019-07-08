#include "io/multicast_receiver.h"

namespace furgbol{
namespace io {
    MulticastReceiver::MulticastReceiver(std::string group_ip, int port) :
        io_(),
        socket_(io_),
        endpoint_(boost::asio::ip::address_v4::any(), port),
        buffer_(new char[4096]) {
        boost::asio::io_service io;
        boost::asio::ip::udp::socket socket(io);
        socket_.open(endpoint_.protocol());
        socket_.set_option(boost::asio::ip::udp::socket::reuse_address(true));
        socket_.bind(endpoint_);
        socket_.set_option(
            boost::asio::ip::multicast::join_group(
                boost::asio::ip::address::from_string(group_ip)));
        datagram = rxcpp::observable<>::create<std::string>(
            [this](rxcpp::subscriber<std::string> s){
                while (1) {
                    size_t n = socket_.receive_from(
                        boost::asio::buffer(buffer_, 4096),
                        endpoint_);
                    s.on_next(std::string(buffer_, n));
                }
            });
    }
    rxcpp::observable<std::string> multicast_datagram(std::string group_ip, int port, int buffer_size) {
        return rxcpp::observable<>::create<std::string>(
            [group_ip, port, buffer_size](rxcpp::subscriber<std::string> s){
                boost::asio::io_service io;
                boost::asio::ip::udp::socket socket(io);
                boost::asio::ip::udp::endpoint endpoint(boost::asio::ip::address_v4::any(), port);
                socket.open(endpoint.protocol());
                socket.set_option(boost::asio::ip::udp::socket::reuse_address(true));
                socket.bind(endpoint);
                socket.set_option(
                    boost::asio::ip::multicast::join_group(
                        boost::asio::ip::address::from_string(group_ip)));
                char *buffer = new char[buffer_size];
                while (1) {
                    size_t n = socket.receive_from(
                        boost::asio::buffer(buffer, 4096),
                        endpoint);
                    s.on_next(std::string(buffer, n));
                }
            });
    }
}
}