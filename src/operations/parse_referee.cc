#include "operations/operations.h"

namespace furgbol {
namespace operators {
    furgbol_op_t<std::string, SSL_Referee> parse_referee() {
        return [](observable<std::string> datagram) {
            return datagram |
                operators::map([](std::string data){
                    SSL_Referee referee;
                    if (!referee.ParseFromString(data)) {
                        throw std::runtime_error("wrapper packet parsing error");
                    }
                    return std::make_shared<SSL_Referee>(std::move(referee)); });};
    }
}
}