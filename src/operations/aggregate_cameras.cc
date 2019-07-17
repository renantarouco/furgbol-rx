#include "operations/operations.h"

namespace furgbol {
namespace operations {
    furgbol_op_t<SSL_DetectionFrame, SSL_DetectionFrame> aggregate_cameras(int n_cameras) {
        return [n_cameras](rxcpp::observable<sptr<SSL_DetectionFrame>> detection$) {
            std::vector<observable<sptr<SSL_DetectionFrame>>> cam_observables;
            detection$ = detection$ |
                operators::publish() |
                operators::ref_count();
            for (int i = 0; i < n_cameras; ++i) {
                cam_observables.push_back(
                    detection$ |
                        operators::filter([i](sptr<SSL_DetectionFrame> det){
                            return det->camera_id() == i; }));
            }
            observable<sptr<SSL_DetectionFrame>> world_frame = cam_observables[0];
            for (int i = 1; i < cam_observables.size(); ++i) {
                world_frame = world_frame |
                    rxcpp::operators::combine_latest(
                        [](sptr<SSL_DetectionFrame> det1, sptr<SSL_DetectionFrame> det2){
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