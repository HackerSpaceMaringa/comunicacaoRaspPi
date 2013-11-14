#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <boost/thread/thread.hpp>
#include <cstdlib>
#include <thread>
#include <utility>
#include <boost/asio.hpp>
#include <boost/ref.hpp>

using namespace std;
using boost::asio::ip::tcp;
typedef boost::shared_ptr<tcp::socket> socket_ptr;

class Management{
    protected:
        virtual void manipulateData(string,socket_ptr){}
        string listenSocket(socket_ptr);
        string getData(socket_ptr);
        string connect(boost::asio::io_service&, unsigned short);

    public:
        void sendMessage(string msg,int port);
        string initSocket(int);
};

#endif
