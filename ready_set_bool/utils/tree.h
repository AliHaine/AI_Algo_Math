#ifndef TREE_H
#define TREE_H

#include <stack>
#include <string>
#include "./utils.h"

template <typename T>
struct Node {
    T value;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(T val) : value(val) {}
};

int calcFromTree(Node<char>* node) {
    if (isConstant(node->value))
        return node->value - 48;
    else if (isUnary(node->value))
        return !(node->left->value);
    else
        return operator_map[node->value](calcFromTree(node->left), calcFromTree(node->right));
}

template <typename T>
Node<T>* treeBuilder(const std::string formula) {
    std::stack<Node<T>*> stack;

    if (!isValidRPN(formula)) {
        std::cout << "The formula " << formula << " is not valid" << std::endl;
        exit(1);
    }

    for (char c : formula) {
        if (isVariable(c)) {
            stack.push(new Node<T>(c));
        } else if (isOperator(c)) {
            Node<T>* childRight = stack.top(); stack.pop();
            Node<T>* childLeft = stack.top(); stack.pop();
            Node<T>* newNode = new Node<T>(c);
            newNode->left = childLeft;
            newNode->right = childRight;
            stack.push(newNode);
        } else {
            Node<T>* child = stack.top(); stack.pop();
            Node<T>* newNode = new Node<T>(c);
            newNode->left = child;
            stack.push(newNode);
        }
    }
    return stack.top();
}

#endif
