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
        int primary_node_id;
        int view;

        std::queue<std::shared_ptr<Message>> buffer;
        std::deque<std::shared_ptr<Reply>> reply_log;

        std::mutex mtx;
        std::condition_variable cv;
    
    public:
        Node();
        
        void print();
        void send_to_client(Client* client, std::shared_ptr<Message> message);
        void buffer_insert(std::shared_ptr<Message> message);
        void read_buffer();
        void read_buffer_continuous();
        void handle_message_type(std::shared_ptr<Message> message);
        void request_handler(std::shared_ptr<Message> message);
};

#endif
