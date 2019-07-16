cmake_minimum_required(VERSION 3.10)
project(furgbol)

find_package(Boost 1.70 COMPONENTS system REQUIRED)
find_Package(Protobuf REQUIRED)

include_directories(
    "include"
    ${Boost_INCLUDE_DIRS}
    ${PROTOBUF_INCLUDE_DIRS}
    "ext/RxCpp/Rx/v2/src"
    "ext/beast"
    "ext/ssl_proto/include")

add_library(furgbol_sources
    "src/sources/multicast_receiver.cc")
target_link_libraries(furgbol_sources
    ${Boost_SYSTEM_LIBRARY})

add_library(furgbol_operators
    "src/operators/parse_wrapper.cc"
    "src/operators/parse_referee.cc"
    "src/operators/get_detection.cc"
    "src/operators/get_geometry.cc"
    "src/operators/aggregate_cameras.cc"
    "src/operators/normalize_ball.cc"
    "src/operators/normalize_robots.cc")
target_link_libraries(furgbol_operators
    "${CMAKE_CURRENT_SOURCE_DIR}/ext/ssl_proto/lib/libssl_proto_sslvision.a"
    "${CMAKE_CURRENT_SOURCE_DIR}/ext/ssl_proto/lib/libssl_proto_refbox.a")

add_executable(furgbol
    "src/main.cc")
target_link_libraries(furgbol
    furgbol_sources
    furgbol_operators
    ${Boost_LIBRARIES}
    ${PROTOBUF_LIBRARIES})
