#include "includes/routing_table.h"
#include "includes/client.h"
#include "includes/node.h"

#include <map>
#include <mutex>
#include <shared_mutex>

std::shared_mutex client_mutex;
std::map<int, Client*> client_map;

std::shared_mutex node_mutex;
std::map<int, Node*> node_map;

void add_node(Node* node){
    std::scoped_lock<std::shared_mutex> lock(node_mutex);

    int node_id = node->get_id();
    node_map[node_id] = node;
}

Node* get_node(int node_id){
    std::shared_lock<std::shared_mutex> lock(node_mutex);

    return node_map[node_id];
}

void delete_node(int node_id){
    std::scoped_lock<std::shared_mutex> lock(node_mutex);

    node_map.erase(node_id);
}

std::deque<int> get_available_node_ids(){
    std::deque<int> available_node_ids;
    
    std::shared_lock<std::shared_mutex> lock(node_mutex);
    for(const auto& [key, value] : node_map){
        available_node_ids.push_back(key);
    }

    lock.unlock();

    return std::move(available_node_ids);
}

void add_client(Client* client){
    std::scoped_lock<std::shared_mutex> lock(client_mutex);
    
    int client_id = client->get_id();
    client_map[client_id] = client;
}

Client* get_client(int client_id){
    std::shared_lock<std::shared_mutex> lock(client_mutex);
    
    return client_map[client_id]; //If it doesn't exists, returns 0
}

void remove_client(int client_id){
    std::scoped_lock<std::shared_mutex> lock(client_mutex);

    client_map.erase(client_id);
}
