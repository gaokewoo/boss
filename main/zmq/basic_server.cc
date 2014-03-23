#include <cppzmq/zmq.hpp>
#include <iostream>
#include <unistd.h>

using namespace std;
using namespace zmq;

int main (void)
{
    context_t context (1);
    // Socket to talk to clients
    socket_t socket (context, ZMQ_REP);

    socket.bind ("tcp://*:5555");

    cout<<"binding on port 5555.\nwaiting client send message...\n"<<endl;

    while (true) 
    {
        // Wait for next request from client
        cout<<"Wait next message"<<endl;
        message_t request;

        socket.recv(&request);
        cout<<(char *)request.data()<<endl;

        // Send reply back to client
        message_t reply (6);
        memcpy ((void *) reply.data (), "World", 6);
        socket.send (reply);

    }

    return 0;
}
