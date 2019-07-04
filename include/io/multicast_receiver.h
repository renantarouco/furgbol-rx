#include <string>

#include <rxcpp/rx.hpp>
#include <boost/asio.hpp>

namespace furgbol {
namespace io {
    class MulticastReceiver {
    private:
        boost::asio::io_service io_;
        boost::asio::ip::udp::socket socket_;
        boost::asio::ip::udp::endpoint endpoint_;
        char *buffer_;
    public:
        MulticastReceiver(std::string, int);
        rxcpp::observable<std::string> datagram;
    };
}
}