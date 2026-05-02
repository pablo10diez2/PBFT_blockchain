#include "includes/app.h"
#include "includes/request.h"
#include "includes/node.h"
#include "includes/client.h"

void init_app(){
    std::vector<std::shared_ptr<Node>> nodes;
    init_nodes(&nodes);

    Client client{};
    Request request1{true, 1};
    Request request2{true, 2};
    
    std::thread launch_threads(thread_manager, &nodes, &client);
    
    client.make_request(false, nodes[0].get());

    launch_threads.join(); 
}

void init_nodes(std::vector<std::shared_ptr<Node>>* nodes){
    for(int i = 0; i < 10; ++i){
        std::shared_ptr<Node> ptr = std::make_shared<Node>();
        nodes->push_back(ptr);
    }
}

void thread_manager(std::vector<std::shared_ptr<Node>>* nodes, Client* client){
    std::vector<std::thread> nodes_read_threads;
    
    std::thread client_read_thread = start_client_read_thread(client);
    start_nodes_read_threads(&nodes_read_threads, nodes);

    client_read_thread.join();

    for(auto& n : nodes_read_threads){
        n.join();
    }
}

std::thread start_client_read_thread(Client* client){
    std::thread t(&Client::read_buffer_continuous, client);

    return std::move(t);
}

void start_nodes_read_threads(std::vector<std::thread>* nodes_read_threads, std::vector<std::shared_ptr<Node>>* nodes){
    for(const auto& node : *nodes){
        std::thread t(&Node::read_buffer_continuous, node);
        
        nodes_read_threads->push_back( std::move(t) );
    }
}
