#include <algorithm>

#include "operators/operators.h"

namespace furgbol {
namespace operators {
    std::function<rxcpp::observable<std::vector<SSL_DetectionRobot>>(rxcpp::observable<SSL_DetectionFrame>)> normalize_robots(int n_robots, definitions::TeamColor color) {
        return [n_robots, color](rxcpp::observable<SSL_DetectionFrame> world_frame) {
            return world_frame |
                rxcpp::operators::map(
                    [n_robots, color](SSL_DetectionFrame detection) {
                        SSL_DetectionRobot base_robot;
                        base_robot.set_confidence(0);
                        std::vector<SSL_DetectionRobot> normalized_robots(n_robots, base_robot);
                        google::protobuf::RepeatedPtrField<SSL_DetectionRobot> robots;
                        if (color == definitions::BLUE) {
                            robots = detection.robots_blue();
                        } else if (color == definitions::YELLOW) {
                            robots = detection.robots_yellow();
                        } else {
                            throw std::runtime_error("no such team color");
                        }
                        std::for_each(robots.begin(), robots.end(), [&normalized_robots](SSL_DetectionRobot r) {
                            if (r.confidence() > normalized_robots[r.robot_id()].confidence()) {
                                normalized_robots[r.robot_id()] = r;
                            }});
                        return normalized_robots; });};
    }
}
}