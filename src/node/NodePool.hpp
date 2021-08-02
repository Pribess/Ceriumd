// Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_NODE_NODEPOOL
#define _CERIUM_NODE_NODEPOOL

#include <vector>
#include <algorithm>

#include "Node.hpp"

class Node;

class NodePool {
    private:
        static std::vector<Node *> pool;
        
        static bool isNodeExist(Node *node);
    public:
        static void AddNode(Node *node);
        static void RemoveNode(Node *node);
        static Node *GetNode(uint32_t addr, unsigned short port);
};

#endif