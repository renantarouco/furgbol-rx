#include <algorithm>

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
    std::function<rxcpp::observable<SSL_DetectionFrame>(rxcpp::observable<SSL_WrapperPacket>)> parse_detection() {
        return [](rxcpp::observable<SSL_WrapperPacket> packet) {
            return packet |
                rxcpp::operators::filter([](SSL_WrapperPacket wp){ return wp.has_detection(); }) |
                rxcpp::operators::map([](SSL_WrapperPacket wp){ return wp.detection(); });};
    }
    std::function<rxcpp::observable<SSL_GeometryData>(rxcpp::observable<SSL_WrapperPacket>)> parse_geometry() {
        return [](rxcpp::observable<SSL_WrapperPacket> packet) {
            return packet |
                rxcpp::operators::filter([](SSL_WrapperPacket wp){ return wp.has_geometry(); }) |
                rxcpp::operators::map([](SSL_WrapperPacket wp){ return wp.geometry(); });};
    }
    std::function<rxcpp::observable<SSL_DetectionFrame>(rxcpp::observable<SSL_DetectionFrame>)> aggregate_cameras(int n_cameras) {
        return [n_cameras](rxcpp::observable<SSL_DetectionFrame> detection) {
            auto cam_observables = std::vector<rxcpp::observable<SSL_DetectionFrame>>{};
            detection = detection |
                rxcpp::operators::subscribe_on(rxcpp::observe_on_new_thread()) |
                rxcpp::operators::publish() |
                rxcpp::operators::ref_count();
            for (int i = 0; i < n_cameras; ++i) {
                cam_observables.push_back(
                    detection |
                        rxcpp::operators::filter([i](SSL_DetectionFrame det){
                            return det.camera_id() == i; }));
            }
            auto world_frame = cam_observables[0];
            for (int i = 1; i < cam_observables.size(); ++i) {
                world_frame = world_frame |
                    rxcpp::operators::combine_latest(
                        [](SSL_DetectionFrame det1, SSL_DetectionFrame det2){
                            for (int i = 0; i < det2.balls_size(); ++i) {
                                auto ball = det1.add_balls();
                                *ball = det2.balls(i);
                            }
                            for (int i = 0; i < det2.robots_blue_size(); ++i) {
                                auto robot = det1.add_robots_blue();
                                *robot = det2.robots_blue(i);
                            }
                            for (int i = 0; i < det2.robots_yellow_size(); ++i) {
                                auto robot = det1.add_robots_yellow();
                                *robot = det2.robots_yellow(i);
                            }
                            return det1; },
                        cam_observables[i]);
            }
            return world_frame; };
    }
    std::function<rxcpp::observable<SSL_DetectionBall>(rxcpp::observable<SSL_DetectionFrame>)> normalize_ball() {
        return [](rxcpp::observable<SSL_DetectionFrame> world_frame) {
            return world_frame |
                rxcpp::operators::filter([](SSL_DetectionFrame det){ return det.balls_size() > 0; }) |
                rxcpp::operators::map([](SSL_DetectionFrame det){
                    return *std::max_element(
                        det.balls().begin(),
                        det.balls().end(),
                        [](SSL_DetectionBall b1, SSL_DetectionBall b2) {
                            return b1.confidence() < b2.confidence(); });});};
    }
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