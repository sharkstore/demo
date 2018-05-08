#ifndef FBASE_DATASERVER_NET_ACCEPTOR_H_
#define FBASE_DATASERVER_NET_ACCEPTOR_H_

#include <asio/io_context.hpp>
#include <asio/ip/tcp.hpp>
#include <thread>

namespace fbase {
namespace dataserver {
namespace net {

class ConnectionManager;

class Acceptor final {
public:
    Acceptor(ConnectionManager& conn_mgr, const std::string& listen_ip, uint16_t listen_port);
    ~Acceptor();

    Acceptor(const Acceptor&) = delete;
    Acceptor& operator=(const Acceptor&) = delete;

private:
    void do_accept();

private:
    ConnectionManager& conn_mgr_;

    asio::io_context context_;
    asio::ip::tcp::acceptor acceptor_;
    std::unique_ptr<std::thread> thr_;
};

}  // namespace net
}  // namespace dataserver
}  // namespace fbase

#endif /* end of include guard: FBASE_DATASERVER_NET_ACCEPTOR_H_ */
