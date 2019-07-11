#include "operators/operators.h"

namespace furgbol {
namespace operators {
    std::function<rxcpp::observable<SSL_GeometryData>(rxcpp::observable<SSL_WrapperPacket>)> get_geometry() {
        return [](rxcpp::observable<SSL_WrapperPacket> packet) {
            return packet |
                rxcpp::operators::filter([](SSL_WrapperPacket wp){ return wp.has_geometry(); }) |
                rxcpp::operators::map([](SSL_WrapperPacket wp){ return wp.geometry(); });};
    }
}
}