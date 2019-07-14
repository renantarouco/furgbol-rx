#include <google/protobuf/util/json_util.h>

#include "operators/operators.h"

namespace furgbol {
namespace operators {
    std::function<rxcpp::observable<std::string>(rxcpp::observable<google::protobuf::Message&>)> serialize_to_json() {
        return [](rxcpp::observable<google::protobuf::Message&> message) {
            return message |
                rxcpp::operators::map(
                    [](google::protobuf::Message &message_) {
                        google::protobuf::util::JsonPrintOptions options;
                        options.always_print_primitive_fields = true;
                        std::string json_str;
                        google::protobuf::util::MessageToJsonString(message_, &json_str, options);
                        return json_str; });};
    }
}
}