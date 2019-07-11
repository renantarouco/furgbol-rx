#ifndef INCLUDE_SOURCES_MULTICAST_RECEIVER_H
#define INCLUDE_SOURCES_MULTICAST_RECEIVER_H

#include <string>
#include <functional>

#include <rxcpp/rx.hpp>
#include <boost/asio.hpp>

namespace furgbol {
namespace sources {
    class MulticastReceiver {
    public:
        MulticastReceiver(std::string, int, int);
        rxcpp::observable<std::string> datagram();
    private:
        boost::asio::io_service io_;
        boost::asio::ip::udp::socket socket_;
        boost::asio::ip::udp::endpoint endpoint_;
        int buffer_size_;
        char *buffer_;
    };
    rxcpp::observable<std::string> multicast_datagram(std::string, int, int);
}
}

#endif