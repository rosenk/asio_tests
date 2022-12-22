#include "connection.h"

#include <spdlog/spdlog.h>

connection::connection(boost::asio::ip::tcp::socket socket, uint64_t connection_id)
    : socket_(std::move(socket))
    , connection_id_(connection_id)
{
}

void connection::operator()(boost::asio::yield_context yield)
{
    for(;;)
    {
        boost::system::error_code ec;
        char data[512];
        size_t length = socket_.async_read_some(boost::asio::buffer(data), yield[ec]);
        if (ec == boost::asio::error::eof) {
            spdlog::info("{} connection closed", connection_id_);
            break;
        }
        else if (ec)
            throw boost::system::system_error(ec); // Some other error.

        spdlog::info("{} received {} bytes", connection_id_, length);
    }
}