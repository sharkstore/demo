#ifndef FBASE_DATASERVER_NET_SERVER_OPT_H_
#define FBASE_DATASERVER_NET_SERVER_OPT_H_

namespace fbase {
namespace dataserver {
namespace net {

struct ServerOption {
    size_t io_threads_num = 4;
    size_t max_connections = 50000;
    size_t read_timeout_ms = 5;
    size_t write_timeout_ms = 5;
    size_t write_queue_capacity = 2000;
};

}  // namespace net
}  // namespace dataserver
}  // namespace fbase



#endif /* end of include guard: FBASE_DATASERVER_NET_SERVER_OPT_H_ */
