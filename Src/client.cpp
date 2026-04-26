#include <includes/client.h>
#include <includes/node.h>

#include <iostream>

Client::Client(int _id) : id(_id) {}

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
