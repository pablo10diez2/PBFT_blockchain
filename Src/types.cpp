#include "includes/types.h"
#include "includes/request.h"
#include "includes/message.h"
#include "includes/reply.h"

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

bool is_message_preprepare(Message* message){
    if(Preprepare* p = dynamic_cast<Preprepare*>(message); p != nullptr){
        return true;
    }
    
    return false;
}
