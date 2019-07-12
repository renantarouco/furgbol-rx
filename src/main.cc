#include <iostream>
#include <thread>
#include <chrono>

#include <rxcpp/rx.hpp>
#include <google/protobuf/util/json_util.h>

#include "definitions/definitions.h"
#include "sources/multicast_receiver.h"
#include "operators/operators.h"

#define DEBUG(S) std::cout << S << std::endl;

namespace Rx {
using namespace rxcpp;
using namespace rxcpp::sources;
using namespace rxcpp::operators;
using namespace rxcpp::util;
}
using namespace Rx;

namespace Furgbol {
  using namespace furgbol::definitions;
  using namespace furgbol::sources;
  using namespace furgbol::operators;
}
using namespace Furgbol;

std::string json_str(google::protobuf::Message *message) {
  google::protobuf::util::JsonPrintOptions options;
  options.always_print_primitive_fields = true;
  std::string json_str;
  google::protobuf::util::MessageToJsonString(*message, &json_str, options);
  return json_str;
}

int main() {
  // Instantiate sources.
  MulticastReceiver vision_mr("224.5.23.1", 10003, 4096);
  MulticastReceiver referee_mr("224.5.23.1", 10003, 4096);
  // Assembly streams.
  auto detection_stream = vision_mr.datagram() |
    parse_wrapper() |
    get_detection() |
    aggregate_cameras(4) |
    serialize_to_json();
  auto referee_stream = referee_mr.datagram() |
    parse_referee();
  auto geometry_stream = vision_mr.datagram() |
    parse_wrapper() |
    get_geometry() |
    serialize_to_json();
  // Instantiate subscribers.
  // WebsocketServer detection_ws();
  // WebsocketServer referee_ws();
  // Bind streams and subscribers.
  // detection_stream.subscribe_on(observe_on_new_thread())
  //   .subscribe(detection_ws.subscriber);
  // referee_stream.subscribe_on(observe_on_new_thread())
  //   .subscribe(referee_ws.subscriber);
  return 0;
}
