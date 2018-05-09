#ifndef FBASE_DATASERVER_NET_PROTOCOL_H_
#define FBASE_DATASERVER_NET_PROTOCOL_H_


namespace fbase {
namespace dataserver {
namespace net {

class Protocol {
public:
    Protocol() {}
    virtual ~Protocol() {}

    Protocol(const Protocol&) = delete;
    Protocol& operator=(const Protocol&) = delete;

    virtual bool Match(const std::array<uint8_t, 4>& preface) = 0;
    virtual void OnDataArrived(const uint8_t* buf, size_t len) = 0;
};


}  // namespace net
}  // namespace dataserver
}  // namespace fbase



#endif /* end of include guard: FBASE_DATASERVER_NET_PROTOCOL_H_ */
