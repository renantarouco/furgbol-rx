#include "consumers/websocket_server.h"

namespace furgbol {
namespace consumers {
    WebsocketServer::WebsocketServer(unsigned int port) : port_(port) {
        auto context = boost::asio::io_service();
    }
}
}