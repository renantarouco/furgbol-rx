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
  //MulticastReceiver mr("224.5.23.1", 10003, 4096);
  SSL_Referee *referee = new SSL_Referee;
  DEBUG(json_str(referee))
  // auto json_ref$ = mr.datagram() |
  //   parse_referee() |
  //   serialize_to_json() |
  //   take(1);
  // json_ref$
  //   .subscribe(
  //     [](std::string json_str) { DEBUG(json_str) });
  return 0;
}
