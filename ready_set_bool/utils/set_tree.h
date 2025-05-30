#ifndef SET_TREE_H
#define SET_TREE_H

#include <iostream>
#include <vector>
#include "./utils.h"

struct Node {
    char op = nullptr;
    std::vector<int> values = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(char val) : op(val) {};
    Node(std::vector<int> val) : values(val) {};
};

Node* treeBuilder(const std::string formula, std::vector<std::vector<int>> sets) {
    std::stack<Node*> stack;

    if (!isValidRPN(formula)) {
        std::cout << "The formula " << formula << " is not valid" << std::endl;
        exit(1);
    }

    for (char c : formula) {
        if (isVariable(c)) {
            stack.push(new Node(c));
        } else if (isOperator(c)) {
            Node* childRight = stack.top(); stack.pop();
            Node* childLeft = stack.top(); stack.pop();
            Node* newNode = new Node(c);
            newNode->left = childLeft;
            newNode->right = childRight;
            stack.push(newNode);
        } else {
            Node* child = stack.top(); stack.pop();
            Node* newNode = new Node(c);
            newNode->left = child;
            stack.push(newNode);
        }
    }
    return stack.top();
}

#endif
