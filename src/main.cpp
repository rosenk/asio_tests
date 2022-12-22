#include "server.h"

#include <spdlog/spdlog.h>
#include <boost/asio.hpp>
#include <boost/asio/spawn.hpp>

using net = boost::asio::ip::tcp;


int main() {
    spdlog::info("service started");

    boost::asio::io_context io_context;

    server server{io_context};

    boost::asio::spawn(io_context, server);

    io_context.run();
}