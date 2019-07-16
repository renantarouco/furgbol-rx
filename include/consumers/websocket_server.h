#ifndef INCLUDE_CONSUMERS_WEBSOCKET_SERVER_H
#define INCLUDE_CONSUMERS_WEBSOCKET_SERVER_H

#include <memory>
#include <string>
#include <iostream>

#include <rxcpp/rx.hpp>
#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <boost/beast/websocket.hpp>

namespace asio = boost::asio;
namespace beast = boost::beast;

namespace furgbol {
namespace consumers {
    class WebsocketServer {
    public:
        WebsocketServer(int port) : ioc_(1), port_(static_cast<unsigned short>(port)) {}
        void run();
    private:
        class Session : public std::enable_shared_from_this<Session> {
        public:
            explicit Session(asio::ip::tcp::socket&& socket) : ws_(std::move(socket)) {}
            void run();
            void on_accept(beast::error_code);
            void do_write(std::string);
            void on_write(beast::error_code, std::size_t);
        private:
            beast::websocket::stream<beast::tcp_stream> ws_;
            beast::flat_buffer buffer_;
        };
        class Listener : public std::enable_shared_from_this<Listener> {
        public:
            Listener(asio::io_context&, asio::ip::tcp::endpoint);
            void run();
            void on_accept(beast::error_code, asio::ip::tcp::socket);
        private:
            asio::io_context& ioc_;
            asio::ip::tcp::acceptor acceptor_;
        };
        asio::io_context ioc_;
        unsigned short port_;
    };
    void log_beast_error(beast::error_code, const char*);
}
}

#endif