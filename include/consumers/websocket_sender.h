#ifndef INCLUDE_CONSUMERS_WEBSOCKET_SENDER_H
#define INCLUDE_CONSUMERS_WEBSOCKET_SENDER_H

#include <memory>

#include <rxcpp/rx.hpp>
#include <boost/asio.hpp>
#include <boost/beast.hpp>

namespace asio = boost::asio;
namespace beast = boost::beast;

namespace furgbol {
namespace consumers {
    class WebsocketSender {
    public:
        WebsocketSender(int);
        void run();
    private:
        asio::io_context ioc_;
        asio::ip::tcp::acceptor acceptor_;
        rxcpp::observable<beast::websocket::stream<asio::ip::tcp::socket>> connection();
        rxcpp::observable<
            std::shared_ptr<
                beast::websocket::stream<
                    asio::ip::tcp::socket>>> new_conn();
    };
}
}

#endif