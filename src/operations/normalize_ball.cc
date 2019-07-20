#include <algorithm>

#include "operations/operations.h"

namespace furgbol {
namespace operations {
  furgbol_op_t<SSL_DetectionFrame, SSL_DetectionFrame> normalize_ball() {
    return [](observable<sptr<SSL_DetectionFrame>> world_frame$) {
      return world_frame$ |
        operators::filter([](sptr<SSL_DetectionFrame> det){
          return det->balls_size() > 0; }) |
        operators::map([](sptr<SSL_DetectionFrame> det) {
          SSL_DetectionBall ball = *std::max_element(
            det->balls().begin(),
            det->balls().end(),
            [](SSL_DetectionBall b1, SSL_DetectionBall b2) {
              return b1.confidence() < b2.confidence(); });
          det->mutable_balls()->Clear();
          SSL_DetectionBall *new_ball = det->add_balls();
          *new_ball = std::move(ball); 
          return std::move(det); }); };
  }
}
}