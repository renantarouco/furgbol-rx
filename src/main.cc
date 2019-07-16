#include <iostream>
#include <thread>
#include <chrono>
#include <memory>

#include <rxcpp/rx.hpp>
#include <google/protobuf/util/json_util.h>

#include "refbox/referee.pb.h"

#include "definitions/definitions.h"
#include "sources/multicast_receiver.h"
#include "operators/operators.h"
#include "consumers/websocket_server.h"

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
  using namespace furgbol::consumers;
}
using namespace Furgbol;

int main() {
  MulticastReceiver referee_mr("224.5.23.1", 10003, 4096);
  auto referee_json_stream = referee_mr.datagram() |
    parse_referee() |
    map([](SSL_Referee message) {
      google::protobuf::util::JsonPrintOptions options;
      options.always_print_primitive_fields = true;
      std::string json_str;
      google::protobuf::util::MessageToJsonString(message, &json_str, options);
      return json_str; }) |
    publish() |
    ref_count() |
    as_dynamic();
  WebsocketServer referee_ws(9002);
  referee_ws.run();  
  return 0;
}
