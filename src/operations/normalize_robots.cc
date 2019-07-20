#include <algorithm>

#include "operations/operations.h"

namespace furgbol {
namespace operations {
  furgbol_op_t<SSL_DetectionFrame, SSL_DetectionFrame> normalize_robots(
    int robots, definitions::TeamColor color) {
    return [robots, color](observable<sptr<SSL_DetectionFrame>> world_frame$) {
      return world_frame$ |
        operators::map(
          [robots, color](sptr<SSL_DetectionFrame> detection) {
            SSL_DetectionRobot base_robot;
            base_robot.set_confidence(0);
            std::vector<SSL_DetectionRobot> normalized_robots(robots, base_robot);
            google::protobuf::RepeatedPtrField<SSL_DetectionRobot> *robots;
            if (color == definitions::BLUE) {
              robots = detection->mutable_robots_blue();
            } else if (color == definitions::YELLOW) {
              robots = detection->mutable_robots_yellow();
            } else {
              throw std::runtime_error("no such team color");
            }
            std::for_each(robots->begin(), robots->end(), [&normalized_robots](SSL_DetectionRobot& r) {
                if (r.confidence() > normalized_robots[r.robot_id()].confidence()) {
                  normalized_robots[r.robot_id()] = std::move(r);
                }});
            robots->Clear();
            for (SSL_DetectionRobot& robot : normalized_robots) {
              SSL_DetectionRobot *new_robot = robots->Add();
              *new_robot = std::move(robot);
            }
            return std::move(detection); });};
  }
}
}