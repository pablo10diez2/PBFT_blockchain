#ifndef TYPES_H
#define TYPES_H

class Message;

bool is_message_request(Message* message);
bool is_message_reply(Message* message);

#endif
