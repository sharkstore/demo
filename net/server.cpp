#include "server.h"

#include "hander.h"

namespace fbase {
namespace dataserver {
namespace net {

Server::Server(const ServerOption& opt) : 
    opt_(opt),
    acceptor_(context_) {
}

Server::~Server() {}

void Server::ListenAndServe(const std::string& listen_ip, uint16_t port, Handler* handler) {
    std::string bind_ip = listen_ip;
    if (bind_ip.empty()) {
        bind_ip = "0.0.0.0";
    }
    try {
        asio::ip::tcp::endpoint endpoint(asio::ip::make_address(bind_ip), listen_port);
        acceptor_.open(endpoint.protocol());
        acceptor_.set_option(asio::ip::tcp::acceptor::reuse_address(true));
        acceptor_.bind(endpoint);
        acceptor_.listen();
    } catch(std::exception& e) {
        std::cerr << "listen on " << bind_ip << ":" << port << " failed: " << e.what() << std::endl;
    }

    std::cout << "listen on " << bind_ip << ":" << port << " successfully." << std::endl;

    handler_ = handler;

    do_accept();
    thr_.reset(new std::thread([this]() {
        try {
            context_.run();
        } catch (...) {
        }
    }));
    thr_->detach();
}


void Server::Stop() {
    acceptor_.close(); 
    context_.stop();
}

}  // namespace net
}  // namespace dataserver
}  // namespace fbase
