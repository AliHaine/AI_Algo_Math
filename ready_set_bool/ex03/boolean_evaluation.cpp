#include <iostream>
#include <stack>
#include <functional>
#include <unordered_map>

#define FULL_CALC true

void tests_simple();
void tests_complex();
void tests_error();

bool eval_formula(std::string formula) {
    std::stack<int> main_stack;
    std::unordered_map<char, std::function<char(int, int)>> operator_map = {
        {'&', [](int a, int b) { return a & b; }},
        {'|', [](int a, int b) { return a | b; }},
        {'^', [](int a, int b) { return a ^ b; }},
        {'=', [](int a, int b) { return a == b; }},
        {'>', [](int a, int b) { return (!a) | b; }},
    };

    int right;
    int left;
    for (char c : formula) {
        if (c == '1' || c == '0') {
            main_stack.push(c - '0');
            continue;
        }
        if (c == '!') {
            right = main_stack.top(); main_stack.pop();
            main_stack.push(!right);
            if (FULL_CALC)
                std::cout << "Calculating " << right << " with ! result: " << main_stack.top() << std::endl;
            continue;
        }
        if (!operator_map.count(c) || main_stack.size() < 2) {
            std::cout << "An error occurred with your formula, please check it." << std::endl;
            exit(1);
        }
        right = main_stack.top(); main_stack.pop();
        left = main_stack.top(); main_stack.pop();
        main_stack.push(operator_map[c](left, right));
        if (FULL_CALC)
            std::cout << "Calculating " << left << " " << right << " with " << c << " result: " << main_stack.top() << std::endl;
    }
    if (main_stack.size() != 1) {
        std::cout << "An error occurred with your formula, please check it." << std::endl;
        exit(1);
    }
    return main_stack.top();
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