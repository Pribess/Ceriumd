//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_NODE_NODEPOOL
#define _CERIUM_NODE_NODEPOOL

#include <vector>

#include "Node.hpp"

class NodePool {
    private:
        static std::vector<Node *> pool;
    public:
        static void AddNode(Node *ptr);
        static void RemoveNode(Node *ptr);
};

#endif