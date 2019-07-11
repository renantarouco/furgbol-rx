cmake_minimum_required(VERSION 3.10)
project(furgbol)

find_package(Boost REQUIRED COMPONENTS system)
find_package(Protobuf REQUIRED)

# Protobuf setup
protobuf_generate_cpp(PROTO_CPP PROTO_H
    src/proto/messages_robocup_ssl_detection.proto
    src/proto/messages_robocup_ssl_geometry.proto
    src/proto/messages_robocup_ssl_wrapper.proto
    src/proto/messages_robocup_ssl_refbox_log.proto
    src/proto/grSim_Replacement.proto
    src/proto/grSim_Commands.proto
    src/proto/grSim_Packet.proto
    src/proto/game_event.proto
    src/proto/rcon.proto
    src/proto/referee.proto
    src/proto/savestate.proto
)

add_library(ssl_proto
    ${PROTO_CPP})
target_link_libraries(ssl_proto
    ${PROTOBUF_LIBRARIES})
# END Protobuf setup

include_directories(
    "include"
    ${CMAKE_CURRENT_BINARY_DIR}
    "ext/RxCpp/Rx/v2/src"
    ${Boost_INCLUDE_DIRS}
    ${PROTOBUF_INCLUDE_DIRS})

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
    "src/operators/normalize_robots.cc"
    "src/operators/serialize_to_json.cc")
target_link_libraries(furgbol_operators
    ssl_proto)

add_executable(furgbol
    "src/main.cc")
target_link_libraries(furgbol
    furgbol_sources
    furgbol_operators)
