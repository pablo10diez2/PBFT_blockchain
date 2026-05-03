class Message;
class Client;

bool is_message_request(Message* message);
bool is_message_reply(Message* message);
Client* get_client_ptr();
void set_client_ptr(Client*);
