#ifndef FBASE_DATASERVER_NET_HANDLER_H_
#define FBASE_DATASERVER_NET_HANDLER_H_

namespace fbase {
namespace dataserver {
namespace net {

class Handler {
public:
    Handler () {}
    virtual ~Handler() {}

    virtual bool HandleRPC() = 0;
    virtual bool HandleTelnet(const std::vector<std::string>& args) = 0;
};

}  // namespace net
}  // namespace dataserver
}  // namespace fbase

#endif /* end of include guard: FBASE_DATASERVER_NET_HANDLER_H_ */
