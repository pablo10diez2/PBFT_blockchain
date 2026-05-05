#ifndef ROUTING_TABLE_H
#define ROUTING_TABLE_H

#include <deque>

class Client;
class Node;

void add_node(Node* node);
Node* get_node(int node_id);
std::deque<int> get_available_node_ids();
void delete_node(int node_id);

void add_client(Client* client);
Client* get_client(int client_id);
void remove_client(int client_id);

#endif
