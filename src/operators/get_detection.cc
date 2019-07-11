#include "operators/operators.h"

namespace furgbol {
namespace operators {
    std::function<rxcpp::observable<SSL_DetectionFrame>(rxcpp::observable<SSL_WrapperPacket>)> get_detection() {
        return [](rxcpp::observable<SSL_WrapperPacket> packet) {
            return packet |
                rxcpp::operators::filter([](SSL_WrapperPacket wp){ return wp.has_detection(); }) |
                rxcpp::operators::map([](SSL_WrapperPacket wp){ return wp.detection(); });};
    }
}
}