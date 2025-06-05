#ifndef SET_TREE_H
#define SET_TREE_H

#include <iostream>
#include <utility>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include "./utils.h"

extern std::vector<int> u;

std::unordered_map<char, std::function<std::vector<int>(std::vector<int>, std::vector<int>)>> vectorOperators = {
		{'!', [](std::vector<int> a, std::vector<int> b) {
			std::vector<int> newVec = {};
			for (auto valA : a) {
				if (std::find(b.begin(), b.end(), valA) == b.end())
					newVec.push_back(valA);
			}
			return newVec;
		}},
		{'&', [](std::vector<int> a, std::vector<int> b) {
			std::vector<int> newVec = {};
			for (auto valA : a) {
				for (auto valB : b) {
					if (valA == valB) {
						newVec.push_back(valA);
						break;
					}
				}
			}
			return newVec;
		}},
		{'|', [](std::vector<int> a, std::vector<int> b) {
			std::vector<int> newVec = {};
			newVec.insert(newVec.end(), a.begin(), a.end());
			newVec.insert(newVec.end(), b.begin(), b.end());
			sort(newVec.begin(), newVec.end());
			newVec.erase(unique(newVec.begin(), newVec.end() ), newVec.end());
			return newVec;
		}},
		{'^', [](std::vector<int> a, std::vector<int> b) {
			std::vector<int> newVec = {};
			for (auto valA : a) {
				if (std::find(b.begin(), b.end(), valA) == b.end())
					newVec.push_back(valA);
			}
			for (auto valB : b) {
				if (std::find(a.begin(), a.end(), valB) == a.end())
					newVec.push_back(valB);
			}
			return newVec;
		}},
		{'=', [](std::vector<int> a, std::vector<int> b) {
			std::vector<int> newVec = {};

			std::sort(a.begin(), a.end());
			std::sort(b.begin(), b.end());
			a.erase(std::unique(a.begin(), a.end()), a.end());
			b.erase(std::unique(b.begin(), b.end()), b.end());
			if (a == b)
				newVec.push_back(1);
			return newVec;
		}},
		{'>', [](std::vector<int> a, std::vector<int> b) {
			return vectorOperators['|'](vectorOperators['!'](u, a), b);
		}},
};

struct Node {
    char op = 0;
    std::vector<int> values;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(char val) : op(val) {};
    Node(std::vector<int> val) : values(std::move(val)) {};
};

void postOrder(Node* node) {
	if (!node) return;
	postOrder(node->left);
	postOrder(node->right);
	if (node->op != 0)
		std::cout << node->op;
	else {
		std::cout << '[';
		for (auto it : node->values) {
			std::cout << it;
		}
		std::cout << ']';
	}
}

Node* treeBuilder(const std::string formula, std::vector<std::vector<int>> sets) {
    std::stack<Node*> stack;
	std::unordered_map<char, std::vector<int>> variableAndValues;
	int index = 0;

    if (!isValidRPN(formula, true)) {
        std::cout << "The formula " << formula << " is not valid" << std::endl;
        exit(1);
    }

    for (char c : formula) {
        if (isVariable(c)) {
			auto varAndValIt = variableAndValues.find(c);
			if (varAndValIt == variableAndValues.end()) {
				if (index >= sets.size()) {
					std::cout << "The formula " << formula << " is not valid" << std::endl;
					exit(1);
				}
				variableAndValues.insert({c, sets.at(index)});
				stack.push(new Node(sets.at(index++)));
			} else {
				stack.push(new Node((varAndValIt->second)));
			}
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
