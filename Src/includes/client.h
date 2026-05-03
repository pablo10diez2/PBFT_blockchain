#ifndef Client_h
#define Client_h

#include <mutex>
#include <queue>
#include <condition_variable>

#include "message.h"

class Node;
class Request;
class Reply;

class Client {
    private:
        int id;
        static int _id;
        std::queue<std::shared_ptr<Message>> buffer;
        std::deque<std::shared_ptr<Request>> request_log;
        std::deque<std::shared_ptr<Reply>> reply_log;
        
        std::mutex mtx;
        std::condition_variable cv;

    public:
        Client();
        int get_id();

        void buffer_insert(std::shared_ptr<Message> message);
        void read_buffer();
        void read_buffer_continuous();
        void send_to_node(Node* node, std::shared_ptr<Message> message);
        void make_request(bool operation, Node* primary_node);
        void handle_message_type(std::shared_ptr<Message> message);
        void reply_handler(std::shared_ptr<Message> message);

};

#endif
