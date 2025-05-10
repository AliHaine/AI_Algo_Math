#include <iostream>
#include <stack>
#include <functional>
#include <unordered_map>

char symbols[] = {'0','1','!','&','|','^','>','='};
std::string equivalents[] = {"⊥","⊤","¬","^","∨","⊕","⇒","⇔"};

bool eval_formula(std::string formula) {
    std::stack<char> main_stack;
    std::unordered_map<char, std::function<int(int, int)>> operator_map = {
        {'&', [](int a, int b) { return a & b; }},
        {'|', [](int a, int b) { return a | b; }},
        {'^', [](int a, int b) { return a ^ b; }},
        {'=', [](int a, int b) { return a == b; }},
        {'>', [](int a, int b) { return (!a) | b; }},
    };

    char operator_char = '&';
    int a = 1;
    int b = 1;

    for (char c : formula) {
        if (c == '1' || c == '0')
            main_stack.push(c);
        std::cout << c << std::endl;
    }

    if (!operator_map.count(operator_char)) {
        std::cout << "not found" << std::endl;
        return false;
    }

    return operator_map[operator_char](a, b);
}

int main(void) {
    std::cout << eval_formula("10&") << std::endl;

    return 0;
}