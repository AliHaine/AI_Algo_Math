#include "utils.h"

std::unordered_map<char, std::function<int(int, int)>> operator_map = {
    {'&', [](int a, int b) { return a & b; }},
    {'|', [](int a, int b) { return a | b; }},
    {'^', [](int a, int b) { return a ^ b; }},
    {'=', [](int a, int b) { return a == b; }},
    {'>', [](int a, int b) { return (!a) | b; }},
};

bool isVariable(char c) {
    return (c >= 'A' && c <= 'Z');
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

bool isValidRPN(const std::string &formula, bool mode) {
    int stack_size = 0;
	std::function<bool(char)> variableFunc = isConstant;
	if (mode)
		variableFunc = isVariable;
    for (char c : formula) {
        if (variableFunc(c))
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