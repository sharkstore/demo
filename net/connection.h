#ifndef FBASE_DATASERVER_NET_CONNECTION_H_
#define FBASE_DATASERVER_NET_CONNECTION_H_

#include <memory>
#include <asio/ip/tcp.hpp>

namespace fbase {
namespace dataserver {
namespace net {

class ConnectionManager;

class Connection : public std::enable_shared_from_this<Connection> {
public:
    Connection(ConnectionManager& manger, asio::io_context& conext, asio::ip::tcp::socket socket);
    ~Connection();

    Connection(const Connection&) = delete;
    Connection& operator=(const Connection&) = delete;

private:
    ConnectionManger& manager;
    asio::io_context& io_context_;
    asio::ip::tcp::socket socket_;

    std::array<char, 8192> buffer_;
};

} /* net */ 
} /* dataserver  */ 
} /* fbase  */ 



#endif /* end of include guard: FBASE_DATASERVER_NET_CONNECTION_H_ */
