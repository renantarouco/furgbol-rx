#include <algorithm>

#include "operators/operators.h"

namespace furgbol {
namespace operators {
    std::function<rxcpp::observable<SSL_DetectionBall>(rxcpp::observable<SSL_DetectionFrame>)> normalize_ball() {
        return [](rxcpp::observable<SSL_DetectionFrame> world_frame) {
            return world_frame |
                rxcpp::operators::filter([](SSL_DetectionFrame det){
                    return det.balls_size() > 0; }) |
                rxcpp::operators::map([](SSL_DetectionFrame det){
                    return *std::max_element(
                            det.balls().begin(),
                            det.balls().end(),
                            [](SSL_DetectionBall b1, SSL_DetectionBall b2) {
                                return b1.confidence() < b2.confidence(); });});};
    }
}
}