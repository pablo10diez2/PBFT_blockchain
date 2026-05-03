#include <iostream>

#include "includes/reply.h"

Reply::Reply(int _view_number, time_t _request_timestamp, int _client_id, 
                int _node_id, bool _result) : view_number(_view_number),
                request_timestamp(_request_timestamp), client_id(_client_id),
                node_id(_node_id), result(_result) {}

void Reply::print(){
    std::cout << "REPLY -> id: " << get_id() << ", view number: " << 
    this->view_number << ", request timestamp: " << this->request_timestamp <<
    ", client id: " << this->client_id << ", node id: " << this->node_id << ", result: " << 
    this->result << std::endl;
}
