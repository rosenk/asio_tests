#ifndef C1835EFF_D7CF_4059_A3CE_2D5C81F77AE6
#define C1835EFF_D7CF_4059_A3CE_2D5C81F77AE6

#include <boost/asio.hpp>
#include <boost/asio/spawn.hpp>

class connection
{
public:
    connection(boost::asio::ip::tcp::socket socket, uint64_t connection_id);

    void operator()(boost::asio::yield_context yield);

private:
    boost::asio::ip::tcp::socket socket_;
    uint64_t connection_id_;
};

#endif /* C1835EFF_D7CF_4059_A3CE_2D5C81F77AE6 */
