#include "includes/message.h"

int Message::_id = 0;

Message::Message() : id(_id) {
    _id++;
}

int Message::get_id(){
    return this->id;
}
