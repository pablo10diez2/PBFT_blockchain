#ifndef ROUTING_TABLE_H
#define ROUTING_TABLE_H

class Client;

void add_client(Client* client);
Client* get_client(int client_id);
void remove_client(int client_id);

#endif
