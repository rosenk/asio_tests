#include "server.h"
#include "connection.h"

#include <spdlog/spdlog.h>


using net = boost::asio::ip::tcp;

server::server(boost::asio::io_context &io_context)
    : io_context_(io_context)
{
}

void server::operator()(boost::asio::yield_context yield) const
{
    net::acceptor acceptor(io_context_, net::endpoint(net::v4(), 1234));
    
    uint64_t connection_id = 0;
    for(;;)
    {
        auto socket = acceptor.async_accept(yield);
        ++connection_id;
        spdlog::info("accepted connection {}", connection_id);

        boost::asio::spawn(io_context_, connection{std::move(socket), connection_id});
    }
}
