#include "operations/operations.h"

namespace furgbol {
namespace operations {
  furgbol_op_t<SSL_WrapperPacket, SSL_GeometryData> get_geometry() {
    return [](observable<sptr<SSL_WrapperPacket>> packet$) {
      return packet$ |
        operators::filter([](sptr<SSL_WrapperPacket> wp){
          return wp->has_geometry(); }) |
        operators::map([](sptr<SSL_WrapperPacket> wp){
          return std::make_shared<SSL_GeometryData>(
            std::move(wp->geometry())); });};
  }
}
}