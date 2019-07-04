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
}
}