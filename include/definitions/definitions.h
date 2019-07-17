#ifndef INCLUDE_DEFINITIONS_DEFINITIONS_H
#define INCLUDE_DEFINITIONS_DEFINITIONS_H

#include <memory>

#include <rxcpp/rx.hpp>

namespace furgbol {
    using namespace rxcpp;
    template<class T> using sptr = std::shared_ptr<T>;
    template<class T> using uptr = std::unique_ptr<T>;
namespace definitions {
    enum TeamColor { BLUE, YELLOW };
}
}

#endif