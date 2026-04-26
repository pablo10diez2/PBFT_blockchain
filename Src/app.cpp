#include "includes/app.h"
#include "includes/client.h"
#include "includes/request.h"

#include <thread>

void init_app(){
    std::vector< std::shared_ptr<Node> > nodes;
    init_nodes(&nodes);

    Client client{};
    Request request1{true, 1};

    std::thread client_read_thread(&Client::read_buffer_continuous, &client);

    nodes[0].get()->send_to_client(&client, &request1);

    client_read_thread.join();
}

void init_nodes(std::vector< std::shared_ptr<Node> >* nodes){
    for(int i = 0; i < 10; ++i){
        std::shared_ptr<Node> ptr = std::make_shared<Node>();
        nodes->push_back(ptr);
    }
}

