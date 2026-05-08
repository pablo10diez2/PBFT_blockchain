#include "includes/preprepare.h"
#include "includes/message.h"

#include <iostream>

Preprepare::Preprepare(int _view_number, int _sequence_number, size_t _message_digest) : view_number(_view_number),
                    sequence_number(_sequence_number), message_digest(_message_digest) {}

void Preprepare::print(){
    std::cout << "PREPREPARE -> id: " << this->get_id() << ", view number: " << this->view_number  << ", sequence_number: "
    << this->sequence_number << ", message digest: " << this->message_digest << std::endl;
}
