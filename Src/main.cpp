#include "includes/client.h"
#include "includes/node.h"

#include <thread>

int main(){
    Client client{0};
    Node node{};

    std::thread client_read_thread(&Client::read_buffer_continuous, &client);
    std::thread node_read_thread(&Node::read_buffer_continuous, &node);
    
    node.send_to_client(&client, 777);
    node.send_to_client(&client, 778);

    client.send_to_node(&node, 555);
    client.send_to_node(&node, 556);

    client_read_thread.join();
    node_read_thread.join();
}
