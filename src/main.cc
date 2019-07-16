#include <iostream>
#include <thread>
#include <chrono>

#include <rxcpp/rx.hpp>
#include <google/protobuf/util/json_util.h>

#include "refbox/referee.pb.h"

#include "definitions/definitions.h"
#include "sources/multicast_receiver.h"
#include "operators/operators.h"

#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <boost/beast/websocket.hpp>

// Leitura de amanhã:
// https://www.youtube.com/watch?v=QGcVXgEVMJg
// https://flames-of-code.netlify.com/blog/rxcpp-copy-operator/
// https://github.com/ReactiveX/RxCpp/issues/451
// http://kirkshoop.github.io/async/rxcpp/c++/2015/08/04/rxcpp_-_moderncpp_events_as_observables.html
// https://medium.com/@benlesh/hot-vs-cold-observables-f8094ed53339

#define DBG(S) std::cout << S << std::endl;

namespace Rx {
using namespace rxcpp;
using namespace rxcpp::sources;
using namespace rxcpp::operators;
using namespace rxcpp::subjects;
using namespace rxcpp::util;
}
using namespace Rx;

namespace Furgbol {
  using namespace furgbol::definitions;
  using namespace furgbol::sources;
  using namespace furgbol::operators;
}
using namespace Furgbol;

void do_session(boost::asio::ip::tcp::socket&, observable<std::string>);

int main() {
  MulticastReceiver referee_mr("224.5.23.1", 10003, 4096);
  auto referee_json_stream = referee_mr.datagram() |
    parse_referee() |
    map([](SSL_Referee message) {
      google::protobuf::util::JsonPrintOptions options;
      options.always_print_primitive_fields = true;
      std::string json_str;
      google::protobuf::util::MessageToJsonString(message, &json_str, options);
      return json_str; });
  try {
      const boost::asio::ip::address address = boost::asio::ip::make_address("0.0.0.0");
      const unsigned short port = static_cast<unsigned short>(9002);
      boost::asio::io_context ioc{ 1 };
      boost::asio::ip::tcp::acceptor acceptor{ ioc, {address, port} };
      for(;;) {
        boost::asio::ip::tcp::socket socket{ ioc };
        acceptor.accept(socket);
        do_session(socket, referee_json_stream);
      }
  } catch (const std::exception& e) {
      std::cerr << "Error: " << e.what() << std::endl;
      return EXIT_FAILURE;
  }
  referee_json_stream.subscribe(
    [](std::string json_str) {
      std::cout << json_str << std::endl; });
  return 0;
}

void do_session(boost::asio::ip::tcp::socket &socket, observable<std::string> message) {
  try {
    boost::beast::websocket::stream<boost::asio::ip::tcp::socket> ws{ std::move(socket) };
    ws.set_option(boost::beast::websocket::stream_base::decorator(
      [](boost::beast::websocket::response_type& res) {
          res.set(boost::beast::http::field::server,
              "furgbol-rx websocket-server-sync"); }));
    ws.accept();
    ws.text(true);
    boost::beast::flat_buffer buffer;
    subject<int> subject;
    message.subscribe(
      [&buffer, &ws](std::string s) {
        boost::beast::ostream(buffer) << s;
        ws.write(buffer.data());
        buffer.clear();
      }
    );
  } catch (boost::beast::system_error const &se) {
    if(se.code() != boost::beast::websocket::error::closed)
      std::cerr << "Error: " << se.code().message() << std::endl;
  } catch (std::exception const &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}
