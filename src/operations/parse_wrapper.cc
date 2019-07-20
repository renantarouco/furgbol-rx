#include "operations/operations.h"

namespace furgbol {
namespace operations {
  furgbol_op_t<std::string, SSL_WrapperPacket> parse_wrapper() {
    return [](observable<sptr<std::string>> datagram$) {
      return datagram$ |
        operators::map([](sptr<std::string> data){
          SSL_WrapperPacket packet;
          if (!packet.ParseFromString(*data)) {
            throw std::runtime_error("referee parsing error");
          }
          return std::make_shared<SSL_WrapperPacket>(
            std::move(packet)); });};
  }
}
}