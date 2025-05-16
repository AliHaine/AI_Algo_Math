#ifndef UTILS_H
#define UTILS_H
#include <iostream>


    struct Node {
        char value;
        Node* left = nullptr;
        Node* right = nullptr;

        Node(char val) : value(val) {}
    };

    bool isVariable(char c) {
        return (c >= 'A' && c <= 'Z') || c == '0' || c == '1';
    }

    bool isConstant(char c) {
       return c == '0' || c == '1';
    }

    bool isOperator(char c) {
        return c == '&' || c == '>' || c == '|' || c == '^' || c == '=';
    }

    bool isUnary(char c) {
        return c == '!';
    }

    int power(int number, int power) {
        int result = number;
        while (--power > 0)
            result *= number;
        return result;
    }

    bool isValidRPN(std::string formula) {
        int stack_size = 0;
        for (char c : formula) {
            if (isVariable(c))
                stack_size++;
            else if (isOperator(c)) {
                if (stack_size < 2) return false;
                stack_size--;
            }
            else if (isUnary(c)) {
                if (stack_size < 1) return false;
            }
            else
                return false;
        }
        return stack_size == 1;
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
#endif