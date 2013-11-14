#include "include/Management.h"

/* For each client to conect create a Thread to do what was ask by the
 * client */

string Management::listenSocket(socket_ptr sock){
    try{
        return getData(sock);
    }catch (std::exception& e){
        std::cerr << "Exception: listenSocket: " << e.what() << "\n";
    }
}

void Management::sendMessage(string msg,int port){
    try{
        boost::asio::io_service io_service;

        tcp::socket socket(io_service);
        tcp::resolver resolver(io_service);
        boost::asio::connect(socket, resolver.resolve({"127.0.0.1",
                    to_string(port).c_str()}));

        boost::system::error_code error;
        cout << "Sending question ..." << endl;
        boost::asio::write(socket, boost::asio::buffer(msg), error);
        cout << "Question sent!" << endl;

    }catch (std::exception& e){
        std::cerr << "Exception: askToServers: " << e.what() << "\n";
    }
}

string Management::getData(socket_ptr sock){
    char data[10000];

    boost::system::error_code error;
    size_t length = sock->read_some(boost::asio::buffer(data), error);

    if (error == boost::asio::error::eof)
        return string("NULL");
    else if (error)
        throw boost::system::system_error(error);

    data[length] = '\0';
    cout << "Question: " << data << endl;

    return string(data);
}

string Management::connect(boost::asio::io_service& io_service,
        unsigned short port){

    tcp::acceptor a(io_service, tcp::endpoint(tcp::v4(), port));
    socket_ptr sock(new tcp::socket(io_service));
    cout << "Waiting connection..." << endl;
    a.accept(*sock);
    cout << "Connection accepted!" << endl;
    return listenSocket(sock);
}

string Management::initSocket(int port){
    try{
        boost::asio::io_service io_service;
        return connect(io_service, port);
    }catch (std::exception& e){
        std::cerr << "Exception: initSocket: " << e.what() << "\n";
    }
}
