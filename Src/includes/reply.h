#ifndef REPLY_H
#define REPLY_H

#include <ctime>

#include "includes/message.h"

class Reply : public Message{
    private:
        int view_number;
        time_t request_timestamp;
        int client_id;
        int node_id;
        bool result;

    public:
        Reply(int _view_number, time_t _request_timestamp, int _client_id, 
                int _node_id, bool _result);
        void print();
};

#endif
