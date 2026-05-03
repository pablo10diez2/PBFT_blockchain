#include "includes/routing_table.h"
#include "includes/client.h"

#include <map>
#include <mutex>
#include <shared_mutex>

std::shared_mutex client_mutex;
std::map<int, Client*> client_map;

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
