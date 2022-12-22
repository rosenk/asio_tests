#ifndef C9EC29BC_631E_4B75_B376_5748CED0FA36
#define C9EC29BC_631E_4B75_B376_5748CED0FA36

#include <boost/asio.hpp>
#include <boost/asio/spawn.hpp>

class server
{
public:
    server(boost::asio::io_context& io_context);

    void operator()(boost::asio::yield_context yield) const;

private:
    boost::asio::io_context& io_context_;
};


#endif /* C9EC29BC_631E_4B75_B376_5748CED0FA36 */
