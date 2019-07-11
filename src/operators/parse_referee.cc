#include "operators/operators.h"

namespace furgbol {
namespace operators {
    std::function<rxcpp::observable<SSL_Referee*>(rxcpp::observable<std::string>)> parse_referee() {
        return [](rxcpp::observable<std::string> datagram) {
            return datagram |
                rxcpp::operators::map([](std::string data){
                    SSL_Referee *referee = new SSL_Referee;
                    if (!referee->ParseFromString(data)) {
                        throw std::runtime_error("wrapper packet parsing error");
                    }
                    return referee; });};
    }
}
}