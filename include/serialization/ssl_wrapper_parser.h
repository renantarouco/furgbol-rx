#include <string>

#include <rxcpp/rx.hpp>

#include "messages_robocup_ssl_detection.pb.h"
#include "messages_robocup_ssl_geometry.pb.h"

namespace furgbol {
namespace serialization {
    class SSLWrapperParser {
    public:
        SSLWrapperParser(rxcpp::observable<std::string>);
        rxcpp::observable<SSL_DetectionFrame> detection;
        rxcpp::observable<SSL_GeometryData> geometry;
    };
}
}