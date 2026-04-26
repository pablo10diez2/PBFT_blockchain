#ifndef APP_H
#define APP_H

#include <vector>
#include <memory>

#include "node.h"

void init_app();
void init_nodes(std::vector< std::shared_ptr<Node> >* nodes);

#endif
