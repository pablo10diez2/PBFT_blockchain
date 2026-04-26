#ifndef Client_h
#define Client_h

#include <mutex>
#include <queue>
#include <condition_variable>

class Node;

class Client {
    private:
        int id;
        std::queue<int> buffer;
        
        std::mutex mtx;
        std::condition_variable cv;

    public:
        Client(int _id);
        int get_id();

        void buffer_insert(int number);
        void read_buffer();
        void read_buffer_continuous();
        void send_to_node(Node* node, int number);
};

#endif
