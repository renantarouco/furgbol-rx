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

add_library(furgbol_operations
    "src/operations/parse_wrapper.cc"
    "src/operations/parse_referee.cc"
    "src/operations/get_detection.cc"
    "src/operations/get_geometry.cc"
    "src/operations/aggregate_cameras.cc"
    "src/operations/normalize_ball.cc"
    "src/operations/normalize_robots.cc")
target_link_libraries(furgbol_operations
    "${CMAKE_CURRENT_SOURCE_DIR}/ext/ssl_proto/lib/libssl_proto_sslvision.a"
    "${CMAKE_CURRENT_SOURCE_DIR}/ext/ssl_proto/lib/libssl_proto_refbox.a")

add_library(furgbol_consumers
    "src/consumers/websocket_server.cc"
    "src/consumers/websocket_sender.cc")
target_link_libraries(furgbol_consumers
    ${Boost_LIBRARIES})

add_executable(furgbol
    "src/main.cc")
target_link_libraries(furgbol
    furgbol_sources
    furgbol_operations
    furgbol_consumers
    ${Boost_LIBRARIES}
    ${PROTOBUF_LIBRARIES})
