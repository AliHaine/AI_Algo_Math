#include <iostream>
#include <stack>
#include <functional>
#include <unordered_map>
#include "../utils/utils.h"

#define FULL_CALC true

std::unordered_map<char, std::function<int(int, int)>> operator_map = {
    {'&', [](int a, int b) { return a & b; }},
    {'|', [](int a, int b) { return a | b; }},
    {'^', [](int a, int b) { return a ^ b; }},
    {'=', [](int a, int b) { return a == b; }},
    {'>', [](int a, int b) { return (!a) | b; }},
};

void tests_simple();
void tests_complex();
void tests_error();

void postOrder(Node* node) {
    if (!node) return;
    postOrder(node->left);
    postOrder(node->right);
    std::cout << node->value << " ";
}

int calcFromTree(Node* node) {
    if (isConstant(node->value))
        return node->value - 48;
    else if (isUnary(node->value))
        return !(node->left->value);
    else
        return operator_map[node->value](calcFromTree(node->left), calcFromTree(node->right));
}

bool eval_formula(std::string formula) {
    Node* tree = treeBuilder(formula);
    return calcFromTree(tree);
}

int main(void) {
    tests_simple();
    //tests_complex();
    //tests_error();
    return 0;
}

void tests_simple() {
    std::cout << eval_formula("10&") << std::endl;     // 1 AND 0 = 0
    std::cout << eval_formula("11&") << std::endl;     // 1 AND 1 = 1

    std::cout << eval_formula("10|") << std::endl;     // 1 OR 0 = 1
    std::cout << eval_formula("00|") << std::endl;     // 0 OR 0 = 0

    std::cout << eval_formula("10^") << std::endl;     // 1 XOR 0 = 1
    std::cout << eval_formula("11^") << std::endl;     // 1 XOR 1 = 0

    std::cout << eval_formula("11=") << std::endl;     // 1 == 1 = 1
    std::cout << eval_formula("01=") << std::endl;     // 1 == 0 = 0

    std::cout << eval_formula("10>") << std::endl;     // 1 ⇒ 0 = 0
    std::cout << eval_formula("01>") << std::endl;     // 0 ⇒ 1 = 1
    std::cout << eval_formula("11>") << std::endl;     // 1 ⇒ 1 = 1
    std::cout << eval_formula("00>") << std::endl;     // 0 ⇒ 0 = 1

    std::cout << eval_formula("10|!") << std::endl;
    std::cout << eval_formula("10>!1=") << std::endl;
}

void tests_complex() {
    std::cout << eval_formula("11&01^|1=") << std::endl;
    std::cout << eval_formula("10>11^0|=") << std::endl;
    std::cout << eval_formula("10&1>01|=") << std::endl;
    std::cout << eval_formula("10>0|1&") << std::endl;
    std::cout << eval_formula("11^0=1>") << std::endl;
    std::cout << eval_formula("110>>") << std::endl;
    std::cout << eval_formula("11=00==") << std::endl;
}

void tests_error() {
    std::cout << eval_formula("&") << std::endl;
    std::cout << eval_formula("1>^") << std::endl;
    std::cout << eval_formula("12&") << std::endl;
    std::cout << eval_formula("1|0>>") << std::endl;
    std::cout << eval_formula("") << std::endl;
}