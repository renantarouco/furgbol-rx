#include "serialization/ssl_wrapper_parser.h"
#include "messages_robocup_ssl_wrapper.pb.h"

namespace furgbol {
namespace serialization {
    SSLWrapperParser::SSLWrapperParser(rxcpp::observable<std::string> datagram) {
        auto packet_ = datagram | 
            rxcpp::operators::map([](std::string data){
                SSL_WrapperPacket packet;
                if (!packet.ParseFromString(data)) {
                    throw std::runtime_error("parsing error");
                }
                return packet;
            }) |
            rxcpp::operators::subscribe_on(rxcpp::observe_on_new_thread()) |
            rxcpp::operators::publish();
        detection = packet_ |
            rxcpp::operators::filter([](SSL_WrapperPacket wp){ return wp.has_detection(); }) |
            rxcpp::operators::map([](SSL_WrapperPacket wp){ return wp.detection(); });
        geometry = packet_ |
            rxcpp::operators::filter([](SSL_WrapperPacket wp){ return wp.has_geometry(); }) |
            rxcpp::operators::map([](SSL_WrapperPacket wp){ return wp.geometry(); });
        packet_.connect();
    }
    std::function<rxcpp::observable<SSL_DetectionFrame>(rxcpp::observable<std::string>)> parse_detection() {
        return [](rxcpp::observable<std::string> multicast_datagram) {
            return multicast_datagram |
                rxcpp::operators::map([](std::string data){
                    SSL_WrapperPacket packet;
                    if (!packet.ParseFromString(data)) {
                        throw std::runtime_error("parsing error");
                    }
                    return packet;
                }) |
                rxcpp::operators::filter([](SSL_WrapperPacket wp){ return wp.has_detection(); }) |
                rxcpp::operators::map([](SSL_WrapperPacket wp){ return wp.detection(); });
        };
    }
}
}