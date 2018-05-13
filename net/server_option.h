#ifndef FBASE_DATASERVER_NET_SERVER_OPT_H_
#define FBASE_DATASERVER_NET_SERVER_OPT_H_

namespace fbase {
namespace dataserver {
namespace net {

struct ServerOption {
    // how many threads will server connections use
    // zero value means share with the accept thread
    size_t io_threads_num = 4;

    // exceeded connection will reject
    size_t max_connections = 50000;

    // connection read timeout
    // a zero value means no timeout
    size_t read_timeout_ms = 5000;

    // connection write request timeout
    size_t write_timeout_ms = 5000;

    // max pending writes per connection
    // TODO: limit memory used by pending writes
    size_t write_queue_capacity = 2000;

    // allowed max packet length when read
    size_t max_packet_length = 10 << 20;
};

}  // namespace net
}  // namespace dataserver
}  // namespace fbase

#endif /* end of include guard: FBASE_DATASERVER_NET_SERVER_OPT_H_ */
