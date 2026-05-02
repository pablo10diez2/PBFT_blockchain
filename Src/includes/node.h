#ifndef Node_h
#define Node_h

#include <queue>
#include <mutex>
#include <condition_variable>

#include "client.h"
#include "message.h"

class Node{
    private:
        int id;
        static int _id;
        std::queue<Message*> buffer;

        std::mutex mtx;
        std::condition_variable cv;
    
    public:
        Node();
        
        void print();
        void send_to_client(Client* client, Message* message);
        void buffer_insert(Message* message);
        void read_buffer();
        void read_buffer_continuous();
};

#endif
