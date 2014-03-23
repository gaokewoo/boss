#include <cppzmq/zmq.hpp>
#include <iostream>
#include <unistd.h>

using namespace std;
using namespace zmq;

int main (void)
{
    context_t context (1);
    // Socket to talk to clients
    socket_t socket (context, ZMQ_SUB);

    socket.connect ("tcp://localhost:5092");

    char* filter = (char*)"xxxx ";
    socket.setsockopt(ZMQ_SUBSCRIBE, filter, strlen(filter));

    while (true) 
    {
        // Wait for next request from client
        cout<<"Wait next message"<<endl;
        message_t pub_info;

        socket.recv(&pub_info);
        cout<<(char *)pub_info.data()<<endl;
    }

    return 0;
}
