#include "acceptor.h"

#include "connection_manager.h"

namespace fbase {
namespace dataserver {
namespace net {

Acceptor::Acceptor(ConnectionManager& conn_mgr, const std::string& listen_ip, uint16_t listen_port)
    : conn_mgr_(conn_mgr), acceptor_(context_) {
    std::string bind_ip = listen_ip;
    if (bind_ip.empty()) {
        bind_ip = "0.0.0.0";
    }
    asio::ip::tcp::endpoint endpoint(asio::ip::make_address(bind_ip), listen_port);
    acceptor_.open(endpoint.protocol());
    acceptor_.set_option(asio::ip::tcp::acceptor::reuse_address(true));
    acceptor_.bind(endpoint);
    acceptor_.listen();

    do_accept();

    thr_.reset(new std::thread([this]() {
        try {
            context_->run();
        } catch (...) {
        }
    }));
    thr_->detach();
}

Acceptor::~Acceptor() { acceptor_.close(); }

void Acceptor::do_accept() {
    acceptor_.async_accept([this](std::error_code ec, asio::ip::tcp::socket socket) {
        if (!ec) {
            conn_mgr_.NewConnection(std::move(socket));
        } else {
            // TOOD: log error
        }
        do_accept();
    });
}

}  // namespace net
}  // namespace dataserver
}  // namespace fbase
