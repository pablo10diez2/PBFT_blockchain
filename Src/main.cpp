#include "client.h"
#include "node.h"

#include <thread>

int main(){
    Client client{0};
    Node node{};

    std::thread t1(&Client::read_buffer, &client);
    
    node.send_to_client(&client, 777);

    t1.join();
}
