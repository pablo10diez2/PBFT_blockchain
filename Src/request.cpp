#include <iostream>

#include "includes/request.h"

Request::Request(bool _operation, int _client_id) : operation(_operation), client_id(_client_id) {
        this->timestamp = time(NULL);
}

void Request::print(){
    std::cout << "REQUEST -> id: " << get_id() << ", operation: " << 
    this->operation << ", client id: " << this->client_id <<
    ", timestamp: " << this->timestamp << std::endl;
}
