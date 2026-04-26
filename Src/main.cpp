#include "includes/client.h"
#include "includes/node.h"

#include <thread>

int main(){
    Client client{0};
    Node node{};

    std::thread t1(&Client::read_buffer_continuous, &client);
    
    node.send_to_client(&client, 777);
    node.send_to_client(&client, 778);

    t1.join();
}
