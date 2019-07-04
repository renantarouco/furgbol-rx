#include <rxcpp/rx.hpp>

#include "messages_robocup_ssl_detection.pb.h"

namespace furgbol {
namespace serialization {
    class SSLDetectionNormalizer {
    public:
        SSLDetectionNormalizer(rxcpp::observable<SSL_DetectionFrame>);
        rxcpp::observable<SSL_DetectionBall> ball;
        rxcpp::observable<std::vector<SSL_DetectionRobot>> robots_blue;
        rxcpp::observable<std::vector<SSL_DetectionRobot>> robots_yellow;
    };
}
}
