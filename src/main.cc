#include <iostream>
#include <thread>
#include <chrono>

#include <rxcpp/rx.hpp>

#include "io/multicast_receiver.h"
#include "serialization/ssl_wrapper_parser.h"
#include "serialization/ssl_detection_aggregator.h"
#include "serialization/ssl_detection_normalizer.h"

namespace Rx {
using namespace rxcpp;
using namespace rxcpp::sources;
using namespace rxcpp::operators;
using namespace rxcpp::util;
}
using namespace Rx;

int main() {
    furgbol::io::MulticastReceiver mr("224.5.23.2", 10020);
    furgbol::serialization::SSLWrapperParser ssl_wp(mr.datagram);
    furgbol::serialization::SSLDetectionAggregator ssl_da(4, ssl_wp.detection);
    furgbol::serialization::SSLDetectionNormalizer ssl_dn(ssl_da.world_frame);
    ssl_dn.ball
        .as_blocking()
        .subscribe([](SSL_DetectionBall ball){
            std::cout << ball.DebugString() << std::endl;
        });
    // auto ball = ssl_da.world_frame |
    //     rxcpp::operators::filter([](SSL_DetectionFrame det){ return det.balls_size() > 0; }) |
    //     rxcpp::operators::flat_map(
    //         [](SSL_DetectionFrame det){
    //             return
    //                 rxcpp::observable<>::iterate(
    //                     std::vector<SSL_DetectionBall>(det.balls().begin(), det.balls().end())
    //                 ) | 
    //                 rxcpp::operators::reduce(
    //                     det.balls(0),
    //                     [](SSL_DetectionBall b1, SSL_DetectionBall b2){
    //                         if (b2.confidence() > b1.confidence()) {
    //                             return b2;
    //                         }
    //                         return b1;
    //                     }
    //                 );
    //         },
    //         [](SSL_DetectionFrame det, SSL_DetectionBall ball){
    //             return ball;
    //         }
    //     );
    // furgbol::serialization::SSLDetectionNormalizer ssl_dn(ssl_da.world_frame);
    // ball
    //     .subscribe_on(observe_on_new_thread())
    //     .as_blocking()
    //     .subscribe([](SSL_DetectionBall ball){
    //         std::cout << ball.DebugString() << std::endl;
    //     });
    // auto full_frame = cam0 | combine_latest(cam1, cam2, cam3);
    // full_frame
    //     .take(1)
    //     .subscribe([](std::tuple<SSL_DetectionFrame, SSL_DetectionFrame, SSL_DetectionFrame, SSL_DetectionFrame> frame){
    //         std::cout << std::get<0>(frame).DebugString() << ",";
    //         std::cout << std::get<1>(frame).DebugString() << ",";
    //         std::cout << std::get<2>(frame).DebugString() << ",";
    //         std::cout << std::get<3>(frame).DebugString() << std::endl;
    //     });
    // auto connection = detection.connect();
    // std::this_thread::sleep_for(std::chrono::seconds(10));
    // connection.unsubscribe();
    return 0;
}