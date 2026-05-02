#include "includes/types.h"
#include "includes/request.h"
#include "includes/message.h"

bool is_message_request(Message* message){
    if(Request* r = dynamic_cast<Request*>(message); r != nullptr){
        return true;
    }
    
    return false;
}


