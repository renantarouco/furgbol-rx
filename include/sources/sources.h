#ifndef INCLUDE_SOURCES_SOURCES_H
#define INCLUDE_SOURCES_SOURCES_H

#include <rxcpp/rx.hpp>
#include <boost/asio.hpp>

namespace furgbol {
namespace sources {
    rxcpp::observable<std::string> multicast_datagram(std::string, int, int);
}
}

#endif