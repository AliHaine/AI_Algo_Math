#include <iostream>
#include <functional>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <stack>
#include "../utils/utils.h"

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
            continue;
        }
        if (!operator_map.count(c) || main_stack.size() < 2) {
            std::cout << std::endl << "An error occurred with your formula, please check it." << std::endl;
            exit(1);
        }
        right = main_stack.top(); main_stack.pop();
        left = main_stack.top(); main_stack.pop();
        main_stack.push(operator_map[c](left, right));
    }
    if (main_stack.size() != 1) {
        std::cout << std::endl << "An error occurred with your formula, please check it." << std::endl;
        exit(1);
    }
    return main_stack.top();
}

bool sat(std::string formula) {
        std::map<char, int> usedVar;
    std::string currentFormula = formula;
    int maxRows = 0;

    for (char c : formula) {
        if (c >= 'A' && c <= 'Z') {
            if (usedVar.count(c) == 0)
                usedVar.insert({c, 0});
        }
    }

    maxRows = power(2, usedVar.size());
    for (int i = 0; i < maxRows-1; i++) {
        for (auto it = usedVar.rbegin(); it != usedVar.rend(); ++it) {
            if (it->second == 0) {
                it->second = 1;
                while (it-- != usedVar.rbegin()) {
                    it->second = 0;
                }
                break;
            }
        }
        for (auto it = usedVar.begin(); it != usedVar.end(); ++it)
            std::replace(currentFormula.begin(),currentFormula.end(), it->first, (char)(it->second+48));
        if (eval_formula(currentFormula))
            return true;
        currentFormula = formula;
    }
    return false;
}

int main(void) {
    std::cout << sat("A!A&") << std::endl;
    std::cout << sat("A!A|") << std::endl;
    std::cout << sat("A!B&C|") << std::endl;
    return 0;
}