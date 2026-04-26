#ifndef Node_h
#define Node_h

#include <queue>
#include <mutex>
#include <condition_variable>

#include "client.h"

class Client;

class Node{
    private:
        int id;
        static int _id;
        std::queue<int> buffer;

        std::mutex mtx;
        std::condition_variable cv;
    
    public:
        Node();
        
        void print();
        void send_to_client(Client* client, int number);
        void buffer_insert(int number);
        void read_buffer();
        void read_buffer_continuous();
};

#endif
