#ifndef INCLUDE_OPERATORS_OPERATORS_H
#define INCLUDE_OPERATORS_OPERATORS_H

#include <functional>
#include <vector>

#include <rxcpp/rx.hpp>

#include "messages_robocup_ssl_wrapper.pb.h"
#include "definitions/definitions.h"

namespace furgbol {
namespace operators {
    std::function<rxcpp::observable<SSL_WrapperPacket>(rxcpp::observable<std::string>)> parse_wrapper();
    std::function<rxcpp::observable<SSL_DetectionFrame>(rxcpp::observable<SSL_WrapperPacket>)> parse_detection();
    std::function<rxcpp::observable<SSL_GeometryData>(rxcpp::observable<SSL_WrapperPacket>)> parse_geometry();
    std::function<rxcpp::observable<SSL_DetectionFrame>(rxcpp::observable<SSL_DetectionFrame>)> aggregate_cameras(int);
    std::function<rxcpp::observable<SSL_DetectionBall>(rxcpp::observable<SSL_DetectionFrame>)> normalize_ball();
    std::function<rxcpp::observable<std::vector<SSL_DetectionRobot>>(rxcpp::observable<SSL_DetectionFrame>)> normalize_robots(int, definitions::TeamColor);
}
}

#endif