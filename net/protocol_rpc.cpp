#include "protocol_rpc.h"

namespace fbase {
namespace dataserver {
namespace net {

bool ProtocolTelnet::Match(const std::array<uint8_t, 4>& preface) {
    return preface == kMagicV1 || preface == kMagicV2;
}

void ProtocolTelnet::OnDataArrived(const uint8_t* buf, size_t len) {
    // TODO:
}

}  // namespace net
}  // namespace dataserver
}  // namespace fbase
