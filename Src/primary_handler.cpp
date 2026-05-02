#include "includes/primary_handler.h"
#include "includes/node.h"

std::shared_ptr<Node> primary_node;
std::shared_mutex primary_shared_mutex;

std::shared_ptr<Node> get_primary_node(){
    std::shared_lock<std::shared_mutex> lock(primary_shared_mutex);
    
    return primary_node;
}

void set_primary_node(std::shared_ptr<Node> new_primary_node){
    std::scoped_lock<std::shared_mutex> lock(primary_shared_mutex);

    primary_node = new_primary_node;
}

