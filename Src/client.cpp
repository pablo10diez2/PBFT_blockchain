#include "includes/client.h"
#include "includes/node.h"
#include "includes/request.h"
#include "includes/types.h"
#include "includes/reply.h"

#include <iostream>

int Client::_id = 0;

Client::Client() : id(_id) {
    _id++;
}

int Client::get_id(){
    return this->id;
}

void Client::buffer_insert(std::shared_ptr<Message> message){
    std::scoped_lock<std::mutex> lock(this->mtx);
    
    this->buffer.push(message);
    this->cv.notify_one();
}

void Client::read_buffer(){
    std::unique_lock<std::mutex> lock(this->mtx);

    cv.wait(lock, [this]{ return !this->buffer.empty(); } );
    
    std::shared_ptr<Message> message = this->buffer.front();
    this->buffer.pop();

    handle_message_type(message);
}

void Client::read_buffer_continuous(){
    while(true){
        read_buffer();
    }
}

void Client::send_to_node(Node* node, std::shared_ptr<Message> message){
    node->buffer_insert(message);
}

void Client::make_request(bool operation, Node* primary_node){
    std::shared_ptr<Request> ptr = std::make_shared<Request>(operation, this->get_id());
    this->request_log.push_back(ptr);

    this->send_to_node(primary_node, ptr);
}

void Client::handle_message_type(std::shared_ptr<Message> message){
    if(is_message_reply(message.get())){
        reply_handler(message);
    }
}

void Client::reply_handler(std::shared_ptr<Message> message){
    Reply* reply = dynamic_cast<Reply*>(message.get());
    
    std::shared_ptr<Reply> ptr = std::make_shared<Reply>(*reply);
    this->reply_log.push_back(ptr);
    
    for(auto const& r : this->reply_log){
        std::cout << "printing from the client reply_handler"<< std::endl;
        r.get()->print();
    }
}
