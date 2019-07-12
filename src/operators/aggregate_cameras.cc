#include "operators/operators.h"

namespace furgbol {
namespace operators {
    std::function<rxcpp::observable<SSL_DetectionFrame*>(rxcpp::observable<SSL_DetectionFrame*>)> aggregate_cameras(int n_cameras) {
        return [n_cameras](rxcpp::observable<SSL_DetectionFrame*> detection) {
            auto cam_observables = std::vector<rxcpp::observable<SSL_DetectionFrame*>>{};
            detection = detection |
                rxcpp::operators::subscribe_on(rxcpp::observe_on_new_thread()) |
                rxcpp::operators::publish() |
                rxcpp::operators::ref_count();
            for (int i = 0; i < n_cameras; ++i) {
                cam_observables.push_back(
                    detection |
                        rxcpp::operators::filter([i](SSL_DetectionFrame *det){
                            return det->camera_id() == i; }));
            }
            auto world_frame = cam_observables[0];
            for (int i = 1; i < cam_observables.size(); ++i) {
                world_frame = world_frame |
                    rxcpp::operators::combine_latest(
                        [](SSL_DetectionFrame *det1, SSL_DetectionFrame *det2){
                            for (int i = 0; i < det2->balls_size(); ++i) {
                                auto ball = det1->add_balls();
                                *ball = det2->balls(i);
                            }
                            for (int i = 0; i < det2->robots_blue_size(); ++i) {
                                auto robot = det1->add_robots_blue();
                                *robot = det2->robots_blue(i);
                            }
                            for (int i = 0; i < det2->robots_yellow_size(); ++i) {
                                auto robot = det1->add_robots_yellow();
                                *robot = det2->robots_yellow(i);
                            }
                            return det1; },
                        cam_observables[i]);
            }
            return world_frame; };
    }
}
}