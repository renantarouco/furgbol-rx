#include "operations/operations.h"

namespace furgbol {
namespace operations {
  std::string to_json(const SSL_Referee& referee) {
    google::protobuf::util::JsonOptions opt;
    opt.always_print_primitive_fields = true;
    std::string jstr;
    google::protobuf::util::MessageToJsonString(referee, &jstr, opt);
    return jstr;
  }

  std::function<observable<std::string>(observable<sptr<models::json_serializable_t>>)> serialize_to_json() {
    return [](observable<sptr<models::json_serializable_t>> object$) {
      return object$ |
        operators::map([](sptr<models::json_serializable_t> object) { 
          return to_json(*object); }); };
  }
}
}