#include <iostream>

#include "includes/node.h"
#include "includes/client.h"

int Node::_id = 0;

Node::Node(){
    this->id = _id;
    _id++;
}

void Node::print(){
    std::cout << "Node " << this->id << std::endl;
}

void Node::send_to_client(Client* client, Message* message){
    client->buffer_insert(message);
}

void Node::buffer_insert(Message* message){
    std::scoped_lock<std::mutex> lock(this->mtx);

    this->buffer.push(message);
    this->cv.notify_one();
}

void Node::read_buffer(){
    std::unique_lock<std::mutex> lock(this->mtx);
    
    cv.wait(lock, [this]{ return !this->buffer.empty(); } );

    this->buffer.front()->print();
    this->buffer.pop();
}   

void Node::read_buffer_continuous(){
    while(true){
        read_buffer();
    }
}
