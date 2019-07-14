#include "consumers/websocket_server.h"

#include <google/protobuf/message.h>
#include <google/protobuf/util/json_util.h>

namespace furgbol {
namespace consumers {
    WebsocketServer::WebsocketServer() : server_() {
        server_.set_access_channels(websocketpp::log::alevel::all);
        server_.clear_access_channels(websocketpp::log::alevel::frame_payload);
        server_.init_asio();
        server_.set_open_handler(
            websocketpp::lib::bind(
                &WebsocketServer::on_open_, this, websocketpp::lib::placeholders::_1));
        server_.set_close_handler(
            websocketpp::lib::bind(
                &WebsocketServer::on_close_, this, websocketpp::lib::placeholders::_1));
    }

    rxcpp::subscriber<std::string> WebsocketServer::subscriber() {
        return rxcpp::make_subscriber<std::string>(
            [](std::string next) {
                std::cout << next << std::endl; },
            [](std::exception_ptr e) {
                std::cout << "error" << std::endl; },
            []() {
                std::cout << "completed" << std::endl; });
    }

    void WebsocketServer::run(unsigned port) {
        try {
            server_.listen(port);
            server_.start_accept();
            server_.run();
        } catch (websocketpp::exception const & e) {
            std::cout << e.what() << std::endl;
        } catch (...) {
            std::cout << "other exception" << std::endl;
        }
    }

    void WebsocketServer::on_open_(websocketpp::connection_hdl conn) {
        connections_.insert(conn);
    }
    
    void WebsocketServer::on_close_(websocketpp::connection_hdl conn) {
        connections_.erase(conn);
    }
}
}