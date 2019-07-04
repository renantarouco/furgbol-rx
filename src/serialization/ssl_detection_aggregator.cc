#include "serialization/ssl_detection_aggregator.h"

namespace furgbol {
namespace serialization {
    SSLDetectionAggregator::SSLDetectionAggregator(int n_cameras, rxcpp::observable<SSL_DetectionFrame> detection) {
        auto detection_ = detection |
            rxcpp::operators::subscribe_on(rxcpp::observe_on_new_thread()) |
            rxcpp::operators::publish();
        auto cam_observables_ = std::vector<rxcpp::observable<SSL_DetectionFrame>>{};
        for (int i = 0; i < n_cameras; ++i) {
            cam_observables_.push_back(
                detection_ |
                    rxcpp::operators::filter([i](SSL_DetectionFrame det){
                        return det.camera_id() == i;
                    })
            );
        }
        world_frame = cam_observables_[0];
        if (cam_observables_.size() > 0) {
            for (int i = 1; i < n_cameras; ++i) {
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
                            return det1;
                        },
                        cam_observables_[i]
                    );
            }
        }
        detection_.connect();
    }
}
}