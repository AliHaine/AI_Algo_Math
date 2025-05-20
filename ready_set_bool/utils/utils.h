#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <functional>
#include <unordered_map>

extern std::unordered_map<char, std::function<int(int, int)>> operator_map;

bool isVariable(char c);

bool isConstant(char c);

bool isOperator(char c);

bool isUnary(char c);

int power(int number, int power);

bool isValidRPN(std::string formula);
#endif