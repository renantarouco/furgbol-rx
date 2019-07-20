#include "operations/operations.h"

namespace furgbol {
namespace operations {
  furgbol_op_t<SSL_DetectionFrame, SSL_DetectionFrame> merge_cameras(int cams) {
    return [&cams](rxcpp::observable<sptr<SSL_DetectionFrame>> detection$) {
      std::vector<observable<sptr<SSL_DetectionFrame>>> cam_observables;
      detection$ = detection$ |
        operators::publish() |
        operators::ref_count();
      for (int i = 0; i < cams; ++i) {
        cam_observables.push_back(
          detection$ |
            operators::filter([i](sptr<SSL_DetectionFrame> det){
              return det->camera_id() == i; }));
      }
      observable<sptr<SSL_DetectionFrame>> world_frame$ = cam_observables[0];
      for (int i = 1; i < cam_observables.size(); ++i) {
        world_frame$ = world_frame$ |
          operators::combine_latest(
            [](sptr<SSL_DetectionFrame> det1, sptr<SSL_DetectionFrame> det2){
              det1->mutable_balls()->MergeFrom(det2->balls());
              det1->mutable_robots_blue()->MergeFrom(det2->robots_blue());
              det1->mutable_robots_yellow()->MergeFrom(det2->robots_yellow());
              return std::move(det1); },
            cam_observables[i]);
      }
      return world_frame$; };
  }
}
}