_Pragma("once");

#include <asio/ip/tcp.hpp>
#include <memory>

namespace fbase {
namespace dataserver {
namespace net {

class Connection : public std::enable_shared_from_this<Connection> {
public:
    Connection(asio::io_context& conext, asio::ip::tcp::socket socket);
    ~Connection();

    Connection(const Connection&) = delete;
    Connection& operator=(const Connection&) = delete;

private:
    asio::io_context& io_context_;
    asio::ip::tcp::socket socket_;

    std::array<uint8_t, 8192> buffer_;
};

}  // namespace net
}  // namespace dataserver
}  // namespace fbase
