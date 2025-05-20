#include "tree.h"

int calcFromTree(Node* node) {
    if (isConstant(node->value))
        return node->value - 48;
    else if (isUnary(node->value))
        return !(node->left->value);
    else
        return operator_map[node->value](calcFromTree(node->left), calcFromTree(node->right));
}

Node* treeBuilder(const std::string formula) {
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