#ifndef Client_h
#define Client_h

#include <mutex>
#include <queue>
#include <condition_variable>

class Client {
    private:
        int id;
        std::queue<int> buffer;
        
        std::mutex mtx;
        std::condition_variable cv;

    public:
        Client(int _id);

        void buffer_insert(int number);
        void read_buffer();
};

#endif
