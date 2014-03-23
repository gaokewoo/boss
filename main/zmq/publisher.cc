#include <cppzmq/zmq.hpp>
#include <string>
#include <iostream>

using namespace zmq;
using namespace std;
int main ()
{
    // Prepare our context and socket
    context_t context (1);
    socket_t socket (context, ZMQ_PUB);

    socket.bind("tcp://*:5555");

    char* filter = (char*)"xxxx ";
    // Do 10 requests, waiting each time for a response
    while(true) {
        char buf[64];
        snprintf(buf, sizeof(buf), "%s Hello World", filter);

        message_t request(strlen(buf)+1);
        memcpy ((void *) request.data (), buf, strlen(buf)+1);
        cout << "Sending Hello " << "..." << endl;
        socket.send (request);

        sleep(1);
    }
    return 0;
}
