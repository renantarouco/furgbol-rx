#include "sources/multicast_receiver.h"

namespace furgbol{
namespace sources {
    MulticastReceiver::MulticastReceiver(std::string group_ip, int port, int buffer_size) :
        io_(),
        socket_(io_),
        endpoint_(boost::asio::ip::address_v4::any(), port),
        buffer_size_(buffer_size),
        buffer_(new char[buffer_size]) {
        asio::io_service io;
        asio::ip::udp::socket socket(io);
        socket_.open(endpoint_.protocol());
        socket_.set_option(asio::ip::udp::socket::reuse_address(true));
        socket_.bind(endpoint_);
        socket_.set_option(
            asio::ip::multicast::join_group(
                asio::ip::address::from_string(group_ip)));
    }
    observable<sptr<std::string>> MulticastReceiver::datagram() {
        return observable<>::create<sptr<std::string>>(
            [this](subscriber<sptr<std::string>> s){
                while (1) {
                    size_t n = socket_.receive_from(
                        asio::buffer(buffer_, buffer_size_),
                        endpoint_);
                    s.on_next(
                        std::make_shared<std::string>(
                            std::move(std::string(buffer_, n))));
                }});
    }
}
}