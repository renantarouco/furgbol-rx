#include <rxcpp/rx.hpp>

#include "messages_robocup_ssl_detection.pb.h"

namespace furgbol {
namespace serialization {
    enum TeamColor { BLUE, YELLOW };
    class SSLDetectionNormalizer {
    public:
        SSLDetectionNormalizer(rxcpp::observable<SSL_DetectionFrame>);
        rxcpp::observable<SSL_DetectionBall> ball;
        rxcpp::observable<std::vector<SSL_DetectionRobot>> robots_blue;
        rxcpp::observable<std::vector<SSL_DetectionRobot>> robots_yellow;
    };
    std::function<rxcpp::observable<SSL_DetectionBall>(rxcpp::observable<SSL_DetectionFrame>)> normalize_ball();
    std::function<rxcpp::observable<SSL_DetectionBall>(rxcpp::observable<SSL_DetectionFrame>)> normalize_robots(TeamColor);
}
}
