#ifndef INCLUDE_OPERATIONS_OPERATIONS_H
#define INCLUDE_OPERATIONS_OPERATIONS_H

#include <functional>
#include <vector>

#include <google/protobuf/util/json_util.h>

#include "sslvision/messages_robocup_ssl_wrapper.pb.h"
#include "refbox/referee.pb.h"

#include "definitions/definitions.h"
#include "models/object.h"

namespace furgbol {
namespace operations {
  template<class I, class O>
  using furgbol_op_t = std::function<observable<sptr<O>>(observable<sptr<I>>)>;
  furgbol_op_t<std::string, SSL_WrapperPacket> parse_wrapper();
  furgbol_op_t<std::string, SSL_Referee> parse_referee();
  furgbol_op_t<SSL_WrapperPacket, SSL_DetectionFrame> get_detection();
  furgbol_op_t<SSL_WrapperPacket, SSL_GeometryData> get_geometry();
  furgbol_op_t<SSL_DetectionFrame, SSL_DetectionFrame> merge_cameras(int);
  furgbol_op_t<SSL_DetectionFrame, SSL_DetectionFrame> normalize_ball();
  furgbol_op_t<SSL_DetectionFrame, SSL_DetectionFrame> normalize_robots(int, definitions::TeamColor);
  std::string to_json(const SSL_Referee&);
  std::function<observable<std::string>(observable<sptr<models::json_serializable_t>>)> serialize_to_json();
}
}

#endif