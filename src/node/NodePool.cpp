// Copyright (c) 2021 Heewon Cho

#include "NodePool.hpp"

std::vector<Node *> NodePool::pool;

bool NodePool::isNodeExist(Node *node) {
    if (std::find(NodePool::pool.begin(), NodePool::pool.end(), node) == NodePool::pool.end()) {
        return false;
    }
    return true;
}

void NodePool::AddNode(Node *node) {
    if (NodePool::isNodeExist(node)) {
        throw std::runtime_error("Same Node Object Already Exist!");
    }
    NodePool::pool.push_back(node);
}

void NodePool::RemoveNode(Node *node) {
    try {
        NodePool::pool.erase(std::find(NodePool::pool.begin(), NodePool::pool.end(), node));
    } catch (std::out_of_range &e) {
        return;
    }
}

Node *NodePool::GetNode(uint32_t addr, unsigned short port) {
    for (Node *cnt : NodePool::pool) {
        std::pair<uint32_t, unsigned short> buff = cnt->GetNetData();

        if (buff.first == addr && buff.second == port) {
            return cnt;
        }
    }
    return NULL;
}