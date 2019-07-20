#ifndef INCLUDE_SOURCES_MULTICAST_RECEIVER_H
#define INCLUDE_SOURCES_MULTICAST_RECEIVER_H

#include <string>

#include <boost/asio.hpp>

#include "definitions/definitions.h"

namespace furgbol {
namespace sources {
    namespace asio = boost::asio;
    class MulticastReceiver {
    public:
        MulticastReceiver(std::string, int, int);
        observable<sptr<std::string>> datagram();
    private:
        asio::io_service io_;
        asio::ip::udp::socket socket_;
        asio::ip::udp::endpoint endpoint_;
        int buffer_size_;
        char* buffer_;
    };
}
}

#endif