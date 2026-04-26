#include <iostream>

#include "includes/node.h"

int Node::_id = 0;

Node::Node(){
    this->id = _id;
    _id++;
}

void Node::print(){
    std::cout << "Node " << this->id << std::endl;
}

void Node::send_to_client(Client* client, int number){
    client->buffer_insert(number);
}
