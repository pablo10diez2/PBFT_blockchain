#ifndef APP_H
#define APP_H

#include <vector>
#include <memory>
#include <thread>

class Node;
class Client;

void init_app();
void init_nodes(std::vector< std::shared_ptr<Node> >* nodes);
std::thread start_client_read_thread(Client* client);
void thread_manager(std::vector<std::shared_ptr<Node>>* nodes, Client* client);
void start_nodes_read_threads(std::vector<std::thread>* nodes_read_threads, std::vector<std::shared_ptr<Node>>* nodes);

#endif
