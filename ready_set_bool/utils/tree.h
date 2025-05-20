#ifndef TREE_H
#define TREE_H

#include <stack>
#include <string>
#include "./utils.h"

struct Node {
    char value;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(char val) : value(val) {}
};

int calcFromTree(Node* node);
Node* treeBuilder(const std::string formula);

#endif
