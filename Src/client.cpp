#include "includes/client.h"
#include "includes/node.h"
#include "includes/request.h"

#include <iostream>

int Client::_id = 0;

Client::Client() : id(_id) {
    _id++;
}

int Client::get_id(){
    return this->id;
}

void Client::buffer_insert(Message* message){
    std::scoped_lock<std::mutex> lock(this->mtx);
    
    this->buffer.push(message);
    this->cv.notify_one();
}

void Client::read_buffer(){
    std::unique_lock<std::mutex> lock(this->mtx);

    cv.wait(lock, [this]{ return !this->buffer.empty(); } );
    
    this->buffer.front()->print();
    
    Message* message_found = this->buffer.front();
    this->buffer.pop();
}

void Client::read_buffer_continuous(){
    while(true){
        read_buffer();
    }
}

void Client::send_to_node(Node* node, Message* message){
    node->buffer_insert(message);
}

void Client::make_request(bool operation, Node* primary_node){
    std::shared_ptr<Request> ptr = std::make_shared<Request>(operation, this->get_id());
    this->request_log.push(ptr);

    this->send_to_node(primary_node, ptr.get());
}
