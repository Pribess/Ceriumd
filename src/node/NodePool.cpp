//Copyright (c) 2021 Heewon Cho

#include "NodePool.hpp"

void NodePool::AddNode(Node *node) {
    NodePool::pool.push_back(node);
}

void NodePool::RemoveNode(Node *node) {
    try {
        NodePool::pool.erase(std::find(NodePool::pool.begin(), NodePool::pool.end(), node));
    } catch (std::out_of_range &e) {
        return;
    }
}