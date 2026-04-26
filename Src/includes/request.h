#ifndef REQUEST_H
#define REQUEST_H

#include "message.h"
#include <time.h>

class Request : Message {
    private:
        bool operation;
        time_t timestamp;
        int client_id;

    public:
        Request(bool _operation, int _client_id);
        void print();
};

#endif
