#include <ctime>

#include "includes/message.h"

class Preprepare : public Message {
    private:
        int view_number;
        int sequence_number;
        size_t message_digest;
        
    public:
        Preprepare(int view_number, int sequence_number, size_t message_digest);
        void print();
};
