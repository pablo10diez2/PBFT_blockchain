#include "includes/client.h"
#include "includes/node.h"
#include "includes/request.h"

#include <thread>

int main(){
    Client client{0};
    Node node{};

    Request request1{ true, client.get_id() };
    Request request2{ false, client.get_id() };

    std::thread client_read_thread(&Client::read_buffer_continuous, &client);
    std::thread node_read_thread(&Node::read_buffer_continuous, &node);
    
    node.send_to_client(&client, &request1);
    client.send_to_node(&node, &request2);

    client_read_thread.join();
    node_read_thread.join();
}
