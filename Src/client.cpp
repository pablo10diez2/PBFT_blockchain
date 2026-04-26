#include <includes/client.h>
#include <iostream>

Client::Client(int _id) : id(_id) {}

void Client::buffer_insert(int number){
    std::scoped_lock<std::mutex> lock(this->mtx);
    
    this->buffer.push(number);
    this->cv.notify_one();
}

void Client::read_buffer(){
    std::unique_lock<std::mutex> lock(this->mtx);

    cv.wait(lock, [this]{ return !this->buffer.empty(); } );
    
    std::cout << this->buffer.front() << std::endl;
    this->buffer.pop();
}

void Client::read_buffer_continuous(){
    while(true){
        read_buffer();
    }
}
