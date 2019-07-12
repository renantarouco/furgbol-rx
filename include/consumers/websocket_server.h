#ifndef INCLUDE_CONSUMERS_WEBSOCKET_SERVER_H
#define INCLUDE_CONSUMERS_WEBSOCKET_SERVER_H

#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio.hpp>
#include <boost/asio/ip/tcp.hpp>

namespace furgbol {
namespace consumers {
    class WebsocketServer {
    public:
        WebsocketServer(unsigned);
    private:
        unsigned port_;
    };
}
}

#endif