#include <iostream>
#include <thread>
#include <chrono>
#include <memory>

#include <rxcpp/rx.hpp>
#include <google/protobuf/util/json_util.h>

#include "refbox/referee.pb.h"

#include "definitions/definitions.h"
#include "sources/multicast_receiver.h"
#include "operations/operations.h"
#include "consumers/websocket_sender.h"

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
using namespace rxcpp::operations;
using namespace rxcpp::subjects;
using namespace rxcpp::util;
}
using namespace Rx;

namespace Furgbol {
  using namespace furgbol::definitions;
  using namespace furgbol::sources;
  using namespace furgbol::operations;
  using namespace furgbol::consumers;
}
using namespace Furgbol;

int main() {
  MulticastReceiver mr("224.2.23.1", 10003, 4096);
  auto referee = mr.datagram() | parse_referee();
  referee.subscribe([](furgbol::sptr<SSL_Referee> ref) { std::cout << ref->DebugString() << std::endl; });
  return 0;
}
