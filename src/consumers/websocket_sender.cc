#include "consumers/websocket_sender.h"

namespace furgbol {
namespace consumers {
    WebsocketSender::WebsocketSender(int port) :
        ioc_(1),
        acceptor_(ioc_, asio::ip::tcp::endpoint(asio::ip::address_v4::any(), static_cast<unsigned short>(port))) {
        
    }
    void WebsocketSender::run() {
        new_conn()
            .subscribe(
                [](std::shared_ptr<beast::websocket::stream<asio::ip::tcp::socket>> ws) {
                    try {
                        ws->accept();
                        beast::flat_buffer buffer;
                        //auto msg = rxcpp::observable<>::interval(std::chrono::seconds(1)).map([](int v) { return std::to_string(v); });
                        auto msg = rxcpp::observable<>::from<std::string>("hello", "123", "test");
                        msg.subscribe(
                            [&buffer, ws](std::string str) {
                                beast::ostream(buffer) << str;
                                ws->write(buffer.data());
                                buffer.consume(buffer.size());
                            }
                        );
                    } catch(beast::system_error const& se) {
                        if(se.code() != beast::websocket::error::closed)
                            std::cerr << "Error: " << se.code().message() << std::endl;
                    }
                    catch(std::exception const& e)
                    {
                        std::cerr << "Error: " << e.what() << std::endl;
                    }    
                }
            );
        // connection()
        //     .subscribe(
        //         [&msg](beast::websocket::stream<asio::ip::tcp::socket> ws) {
        //             try {
        //                 ws.accept();
        //                 beast::flat_buffer buffer;
        //                 msg.subscribe(
        //                     [&buffer, &ws](std::string str) {
        //                         beast::ostream(buffer) << str;
        //                         ws.write(buffer.data());
        //                     }
        //                 );
        //             } catch(beast::system_error const& se) {
        //                 if(se.code() != beast::websocket::error::closed)
        //                     std::cerr << "Error: " << se.code().message() << std::endl;
        //             }
        //             catch(std::exception const& e)
        //             {
        //                 std::cerr << "Error: " << e.what() << std::endl;
        //             }
        //         }
        //     );
    }
    // rxcpp::observable<beast::websocket::stream<asio::ip::tcp::socket>> WebsocketSender::connection() {
    //     return rxcpp::observable<>::create<beast::websocket::stream<asio::ip::tcp::socket>>(
    //         [this](rxcpp::subscriber<beast::websocket::stream<asio::ip::tcp::socket>> s) {
    //             while (1) {
    //                 try {
    //                     asio::ip::tcp::socket socket(ioc_);
    //                     acceptor_.accept(socket);
    //                     beast::websocket::stream<asio::ip::tcp::socket> ws(std::move(socket));
    //                     ws.set_option(beast::websocket::stream_base::decorator(
    //                         [](beast::websocket::response_type& res) {
    //                             res.set(
    //                                 beast::http::field::server,
    //                                 "furgbol-rx-websocket-sender"); }));
    //                     ws.text(ws.got_text());
    //                     s.on_next(std::move(ws));
    //                 } catch (boost::system::system_error& e) {
    //                     s.on_error(rxcpp::util::make_error_ptr(e));
    //                 }
    //             }
    //         }
    //     );
    // }
    rxcpp::observable<
        std::shared_ptr<
            beast::websocket::stream<asio::ip::tcp::socket>>> WebsocketSender::new_conn() {
        return rxcpp::observable<>::create<
            std::shared_ptr<
                beast::websocket::stream<asio::ip::tcp::socket>>>(
            [this](rxcpp::subscriber<
                std::shared_ptr<
                    beast::websocket::stream<asio::ip::tcp::socket>>> s) {
                while (1) {
                    try {
                        asio::ip::tcp::socket socket(ioc_);
                        acceptor_.accept(socket);
                        std::shared_ptr<
                            beast::websocket::stream<asio::ip::tcp::socket>> ws = std::make_shared<beast::websocket::stream<asio::ip::tcp::socket>>(std::move(socket));
                        ws->set_option(beast::websocket::stream_base::decorator(
                            [](beast::websocket::response_type& res) {
                                res.set(
                                    beast::http::field::server,
                                    "furgbol-rx-websocket-sender"); }));
                        ws->text(ws->got_text());
                        s.on_next(ws);
                    } catch (boost::system::system_error& e) {
                        s.on_error(rxcpp::util::make_error_ptr(e));
                    }
                }
            }
        );
    }
}
}