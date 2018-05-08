#include <stdio.h>

#include "acceptor.h"

using namespace fbase::dataserver::net;

int main() {
    Acceptor acceptor("127.0.0.1", 1234); 
//    Acceptor acceptor("0.0.0.0", 1234);
    getchar();
}
