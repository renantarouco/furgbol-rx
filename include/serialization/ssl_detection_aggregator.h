#include <rxcpp/rx.hpp>

#include "messages_robocup_ssl_detection.pb.h"

namespace furgbol {
namespace serialization {
    class SSLDetectionAggregator {
    public:
        SSLDetectionAggregator(int, rxcpp::observable<SSL_DetectionFrame>);
        rxcpp::observable<SSL_DetectionFrame> world_frame;
    };
}
}