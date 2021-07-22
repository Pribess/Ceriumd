//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_NODE_NODEPOOL
#define _CERIUM_NODE_NODEPOOL

#include <vector>
#include <algorithm>

#include "Node.hpp"

class NodePool {
    private:
        static std::vector<Node *> pool;
    public:
        static void AddNode(Node *node);
        static void RemoveNode(Node *node);
};

#endif