#include "consumers/websocket_server.h"

namespace furgbol {
namespace consumers {
    void log_beast_error(beast::error_code ec, const char* what) {
        std::cerr << what << "error: " << ec.message() << std::endl;
    }
    void WebsocketServer::run() {
        std::make_shared<WebsocketServer::Listener>(
            ioc_, boost::asio::ip::tcp::endpoint(
                asio::ip::address_v4::any(), port_))->run();
        ioc_.run();
    }
    void WebsocketServer::Session::run() {
        ws_.set_option(
            beast::websocket::stream_base::timeout::suggested(
                beast::role_type::server));
        ws_.set_option(beast::websocket::stream_base::decorator(
            [](beast::websocket::response_type& res) {
                res.set(
                    beast::http::field::server,
                    "furgbol-rx-websocket-async-server"); }));
        ws_.async_accept(
            beast::bind_front_handler(
                &Session::on_accept,
                shared_from_this()));
    }
    void WebsocketServer::Session::on_accept(beast::error_code ec) {
        if (ec) {
            log_beast_error(ec, "on_accept");
            return;
        }
        auto tick = rxcpp::observable<>::interval(std::chrono::seconds(1))
            .map([](int v) { return std::to_string(v); });
        tick.subscribe(
            [this](std::string msg) { do_write(msg); });
    }
    void WebsocketServer::Session::do_write(std::string msg) {
        ws_.text(ws_.got_text());
        boost::beast::ostream(buffer_) << msg;
        ws_.async_write(
            buffer_.data(),
            beast::bind_front_handler(
                &Session::on_write,
                shared_from_this()));
    }
    void WebsocketServer::Session::on_write(beast::error_code ec, std::size_t bytes_transferred) {
        boost::ignore_unused(bytes_transferred);
        if (ec) {
            log_beast_error(ec, "on_write");
            return;
        }
        buffer_.consume(buffer_.size());
    }
    WebsocketServer::Listener::Listener(
        asio::io_context& ioc,
        asio::ip::tcp::endpoint endpoint) : ioc_(ioc), acceptor_(ioc) {
        beast::error_code ec;
        acceptor_.open(endpoint.protocol(), ec);
        if (ec) {
            log_beast_error(ec, "acceptor_.open");
            return;
        }
        acceptor_.set_option(asio::socket_base::reuse_address(true), ec);
        if(ec) {
            log_beast_error(ec, "acceptor_.set_option");
            return;
        }
        acceptor_.bind(endpoint, ec);
        if(ec) {
            log_beast_error(ec, "acceptor_.bind");
            return;
        }
        acceptor_.listen(asio::socket_base::max_listen_connections, ec);
        if(ec) {
            log_beast_error(ec, "acceptor_.listen");
            return;
        }
    }
    void WebsocketServer::Listener::run() {
        acceptor_.async_accept(
            asio::make_strand(ioc_),
            beast::bind_front_handler(
                &Listener::on_accept,
                shared_from_this()));
    }
    void WebsocketServer::Listener::on_accept(beast::error_code ec, asio::ip::tcp::socket socket) {
        if(ec) {
            log_beast_error(ec, "accept");
        } else {
            std::make_shared<WebsocketServer::Session>(std::move(socket))->run();
        }
        run();
    }
}
}