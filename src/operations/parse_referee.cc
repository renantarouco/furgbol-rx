#include "operations/operations.h"

namespace furgbol {
namespace operations {
  furgbol_op_t<std::string, SSL_Referee> parse_referee() {
    return [](observable<sptr<std::string>> datagram$) {
      return datagram$ |
        operators::map([](sptr<std::string> data){
          SSL_Referee referee;
          if (!referee.ParseFromString(*data)) {
            throw std::runtime_error("wrapper packet parsing error");
          }
          return std::make_shared<SSL_Referee>(std::move(referee)); });};
  }
}
}