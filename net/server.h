_Pragma("once");

#include <asio/io_context.hpp>
#include <asio/ip/tcp.hpp>
#include <thread>

namespace fbase {
namespace dataserver {
namespace net {

class Handler;

class Server final {
public:
    explicit Server(const ServerOption& opt);
    ~Server() {}

    Server(const Server&) = delete;
    Server& operator=(const Server&) = delete;

    void ListenAndServe(const std::string& listen_ip, uint16_t port, Handler* handler);
    void Stop();

private:
    void do_accept();

private:
    const ServerOption opt_;

    Handler* handler_ = nullptr;

    // acceptor
    asio::io_context context_;
    asio::ip::tcp::acceptor acceptor_;
    std::unique_ptr<std::thread> thr_;

    //
};

}  // namespace net
}  // namespace dataserver
}  // namespace fbase
