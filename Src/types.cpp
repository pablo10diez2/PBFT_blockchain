#include "includes/types.h"
#include "includes/request.h"
#include "includes/message.h"
#include "includes/reply.h"

Client* client;

bool is_message_request(Message* message){
    if(Request* r = dynamic_cast<Request*>(message); r != nullptr){
        return true;
    }
    
    return false;
}

bool is_message_reply(Message* message){
    if(Reply* r = dynamic_cast<Reply*>(message); r != nullptr){
        return true;
    }

    return false;
}

Client* get_client_ptr(){
    return client;
}

void set_client_ptr(Client* new_client_ptr){
    client = new_client_ptr;
}

