#ifndef FBASE_DATASERVER_NET_CONN_MANAGER_H_
#define FBASE_DATASERVER_NET_CONN_MANAGER_H_

namespace fbase {
namespace dataserver {
namespace net {

class ConnectionManager final {
public:
    ConnectionManager(size_t max_conn_limit);
    ~ConnectionManager();

    ConnectionManager(const ConnectionManager&) = delete;
    ConnectionManager& operator=(const ConnectionManager&) = delete;

    void NewConnection(asio::ip::tcp::socket socket);

private:
    const size_t max_conn_limit_;
};

} /* net */
} /* dataserver  */
} /* fbase  */

#endif /* end of include guard: FBASE_DATASERVER_NET_CONN_MANAGER_H_ */
