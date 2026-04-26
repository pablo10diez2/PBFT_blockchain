#ifndef Node_h
#define Node_h

#include <queue>

#include "client.h"

class Node{
    private:
        int id;
        static int _id;
        std::queue<int> buffer;
    
    public:
        Node();
        
        void print();
        void send_to_client(Client* client, int number);
};

#endif
