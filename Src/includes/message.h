#ifndef MESSAGE_H
#define MESSAGE_H

class Message {
    private:
        int id;
        static int _id;

    public:
        Message();
        int get_id();

        virtual void print() = 0;
};

#endif
