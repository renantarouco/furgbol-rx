#ifndef INCLUDE_CONSUMERS_WEBSOCKET_SERVER_H
#define INCLUDE_CONSUMERS_WEBSOCKET_SERVER_H

#include <set>

#include <rxcpp/rx.hpp>
#include <websocketpp/server.hpp>
#include <websocketpp/config/asio_no_tls.hpp>

namespace furgbol {
namespace consumers {
    class WebsocketServer {
    public:
        WebsocketServer();
        void run(unsigned);
        rxcpp::subscriber<std::string> subscriber();
    private:
        websocketpp::server<websocketpp::config::asio> server_;
        std::set<websocketpp::connection_hdl, std::owner_less<websocketpp::connection_hdl>> connections_;
        void on_open_(websocketpp::connection_hdl);
        void on_close_(websocketpp::connection_hdl);
    };
}
}

#endif