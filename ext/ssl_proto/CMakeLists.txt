cmake_minimum_required(VERSION 3.10)
project(ssl_proto)

find_package(Protobuf REQUIRED)

# GENERATE FILES

protobuf_generate_cpp(SSLVISION_PROTO_CPP SSLVISION_PROTO_H
    proto/sslvision/messages_robocup_ssl_detection.proto
    proto/sslvision/messages_robocup_ssl_geometry.proto
    proto/sslvision/messages_robocup_ssl_wrapper.proto
    proto/sslvision/messages_robocup_ssl_refbox_log.proto)

protobuf_generate_cpp(REFBOX_PROTO_CPP REFBOX_PROTO_H
    proto/refbox/game_event.proto
    proto/refbox/rcon.proto
    proto/refbox/referee.proto
    proto/refbox/savestate.proto)

protobuf_generate_cpp(GRSIM_PROTO_CPP GRSIM_PROTO_H
    proto/grSim/grSim_Commands.proto
    proto/grSim/grSim_Packet.proto
    proto/grSim/grSim_Replacement.proto)

# CREATE LIBS AND LINKS

add_library(${PROJECT_NAME}_sslvision
    ${SSLVISION_PROTO_CPP})
target_link_libraries(${PROJECT_NAME}_sslvision
    ${PROTOBUF_LIBRARIES})

add_library(${PROJECT_NAME}_refbox
    ${REFBOX_PROTO_CPP})
target_link_libraries(${PROJECT_NAME}_refbox
    ${PROTOBUF_LIBRARIES})

add_library(${PROJECT_NAME}_grSim
    ${GRSIM_PROTO_CPP})
target_link_libraries(${PROJECT_NAME}_grSim
    ${PROTOBUF_LIBRARIES})

# INSTALL TARGETS AND HEADERS

install(TARGETS ${PROJECT_NAME}_sslvision
    DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/lib)
install(FILES ${SSLVISION_PROTO_H}
    DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/include/sslvision)

install(TARGETS ${PROJECT_NAME}_refbox
    DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/lib)
install(FILES ${REFBOX_PROTO_H}
    DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/include/refbox)

install(TARGETS ${PROJECT_NAME}_grSim
    DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/lib)
install(FILES ${GRSIM_PROTO_H}
    DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/include/grSim)