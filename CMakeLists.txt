cmake_minimum_required(VERSION 2.6)
project(demo CXX)

set(CMAKE_CXX_STANDARD 11)

set(CXX_FLAGS
    -std=c++11
    -Wall
    -Wextra
    -Wformat
    -Wsign-compare
    -Wno-unused-parameter
    -Wno-unused-variable
    -Woverloaded-virtual
    -Wnon-virtual-dtor
    -Wno-missing-field-initializers
    -DASIO_STANDALONE
)

string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}") 

set(demo_SRCS
    net/connection.cpp
    net/main.cpp
    net/server.cpp
    net/context_pool.cpp
    net/protocol_telnet.cpp
    net/protocol_rpc.cpp
    )

set(dep_LIBS
    pthread
    )

add_executable(demo ${demo_SRCS})
target_link_libraries(demo ${dep_LIBS})
