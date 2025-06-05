#ifndef TREE_H
#define TREE_H

#include <stack>
#include <string>
#include "./utils.h"

struct Node {
	char	value;
	Node* left = nullptr;
	Node* right = nullptr;

	Node(char val) : value(val) {};
};

void inOrder(Node* node) {
	if (!node) return;
	inOrder(node->left);
	std::cout << node->value;
	inOrder(node->right);
}

void postOrder(Node* node) {
	if (!node) return;
	postOrder(node->left);
	postOrder(node->right);
	std::cout << node->value;
}

Node* createNodeWithValues(char value, Node* left, Node* right) {
	Node* newNode = new Node(value);
	newNode->left = left;
	newNode->right = right;
	return newNode;
}

int calcFromTree(Node* node) {
	if (isConstant(node->value))
		return node->value - 48;
	else if (isUnary(node->value))
        return !(node->left->value - 48);
	else
		return operator_map[node->value](calcFromTree(node->left), calcFromTree(node->right));
}

Node* treeBuilder(const std::string &formula, bool mode) {
	std::stack<Node*> stack;

	if (!isValidRPN(formula, mode)) {
		std::cout << "The formula " << formula << " is not valid" << std::endl;
		exit(1);
	}

	for (char c : formula) {
		if (isVariable(c) || isConstant(c)) {
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
