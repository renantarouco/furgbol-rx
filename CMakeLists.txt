cmake_minimum_required(VERSION 3.10)
project(furgbol)

find_package(Boost REQUIRED COMPONENTS system)
find_package(Protobuf REQUIRED)

protobuf_generate_cpp(PROTO_CPP PROTO_H
    src/serialization/proto/messages_robocup_ssl_detection.proto
    src/serialization/proto/messages_robocup_ssl_geometry.proto
    src/serialization/proto/messages_robocup_ssl_wrapper.proto
    src/serialization/proto/messages_robocup_ssl_refbox_log.proto
    src/serialization/proto/grSim_Replacement.proto
    src/serialization/proto/grSim_Commands.proto
    src/serialization/proto/grSim_Packet.proto
)

include_directories(
    "include"
    ${CMAKE_CURRENT_BINARY_DIR}
    "ext/RxCpp/Rx/v2/src"
    ${Boost_INCLUDE_DIRS}
    ${PROTOBUF_INCLUDE_DIRS})

add_library(furgbol_io
    "src/io/multicast_receiver.cc")
target_link_libraries(furgbol_io
    ${Boost_SYSTEM_LIBRARY})

add_library(furgbol_serialization
    ${PROTO_CPP}
    "src/serialization/ssl_wrapper_parser.cc"
    "src/serialization/ssl_detection_aggregator.cc"
    "src/serialization/ssl_detection_normalizer.cc")
target_link_libraries(furgbol_serialization
    ${PROTOBUF_LIBRARIES})

add_library(furgbol_sources
    "src/sources/sources.cc")
target_link_libraries(furgbol_sources
    ${Boost_SYSTEM_LIBRARY})

add_library(furgbol_operators
    ${PROTO_CPP}
    "src/operators/operators.cc")
target_link_libraries(furgbol_operators
    ${PROTOBUF_LIBRARIES})

add_executable(furgbol
    "src/main.cc")
target_link_libraries(furgbol
    furgbol_io
    furgbol_serialization
    furgbol_sources
    furgbol_operators)
