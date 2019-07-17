#include "operators/operators.h"

namespace furgbol {
namespace operators {
    std::function<rxcpp::observable<SSL_WrapperPacket>(rxcpp::observable<std::string>)> parse_wrapper() {
        return [](rxcpp::observable<std::string> datagram) {
            return datagram |
                rxcpp::operators::map([](std::string data){
                    SSL_WrapperPacket packet;
                    if (!packet.ParseFromString(data)) {
                        throw std::runtime_error("wrapper packet parsing error");
                    }
                    return packet; });};
    }
}
}