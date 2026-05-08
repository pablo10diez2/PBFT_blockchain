#include <iostream>

#include "includes/node.h"
#include "includes/client.h"
#include "includes/request.h"
#include "includes/types.h"
#include "includes/routing_table.h"
#include "includes/reply.h"
#include "includes/preprepare.h"

int Node::_id = 0;

Node::Node(){
    this->id = _id;
    _id++;

    this->view = 0;
    this->primary_node_id = 0;
}

int Node::get_id(){
    return this->id;
}

void Node::print(){
    std::cout << "Node " << this->id << std::endl;
}

void Node::send_to_client(Client* client, std::shared_ptr<Message> message){
    client->buffer_insert(message);
}

void Node::multicast(std::shared_ptr<Message> message){
    std::deque<int> available_nodes = get_available_node_ids();
    
    for(const auto& i : available_nodes){
        Node* node = get_node(i);

        if(node != 0 && i != this->id){
            node->buffer_insert(message);
        }
    }
}

void Node::buffer_insert(std::shared_ptr<Message> message){
    std::scoped_lock<std::mutex> lock(this->mtx);

    this->buffer.push(message);
    this->cv.notify_one();
}

void Node::read_buffer(){
    std::unique_lock<std::mutex> lock(this->mtx);
    
    cv.wait(lock, [this]{ return !this->buffer.empty(); } );

    std::shared_ptr<Message> message = this->buffer.front();
    this->buffer.pop();
    
    message.get()->print();

    handle_message_type(message);
}   

void Node::read_buffer_continuous(){
    while(true){
        read_buffer();
    }
}

void Node::handle_message_type(std::shared_ptr<Message> message){
    if(is_message_request(message.get())){
        request_handler(message);
    }
}

void Node::request_handler(std::shared_ptr<Message> message){
    Request* request = dynamic_cast<Request*>(message.get());
    
    std::shared_ptr<Preprepare> preprepare = std::make_shared<Preprepare>(0,0,0);
    
    this->multicast(preprepare);
}
