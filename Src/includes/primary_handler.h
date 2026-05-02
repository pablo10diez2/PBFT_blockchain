#ifndef PRIMARY_HANDLER_H
#define PRIMARY_HANDLER_H

#include <shared_mutex>
#include <memory>

class Node;

std::shared_ptr<Node> get_primary_node();
void set_primary_node(std::shared_ptr<Node> new_primary_node);

#endif
