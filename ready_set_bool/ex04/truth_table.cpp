#include <list>
#include <iostream>
#include <stack>
#include <functional>
#include <unordered_map>
#include <map>
#include <algorithm>

std::list<char> allowedOperators = {'&', '|', '^', '=', '>'};

int power(int number, int power) {
    int result = number;
    while (--power > 0)
        result *= number;
    return result;
}

bool is_allowed_operator(char op) {
    for (char c : allowedOperators) {
        if (c == op)
            return true;
    }
    return false;
}

bool eval_formula(std::string formula) {
    std::stack<int> main_stack;
    std::unordered_map<char, std::function<char(int, int)>> operator_map = {
        {'&', [](int a, int b) { return a & b; }},
        {'|', [](int a, int b) { return a | b; }},
        {'^', [](int a, int b) { return a ^ b; }},
        {'=', [](int a, int b) { return a == b; }},
        {'>', [](int a, int b) { return (!a) | b; }},
    };

    int a;
    int b;
    for (char c : formula) {
        if (c == '1' || c == '0') {
            main_stack.push(c - '0');
            continue;
        }
        if (!operator_map.count(c) || main_stack.size() < 2) {
            std::cout << std::endl << "An error occurred with your formula, please check it." << std::endl;
            exit(1);
        }
        a = main_stack.top(); main_stack.pop();
        b = main_stack.top(); main_stack.pop();
        main_stack.push(operator_map[c](a, b));
    }
    if (main_stack.size() != 1) {
        std::cout << std::endl << "An error occurred with your formula, please check it." << std::endl;
        exit(1);
    }
    return main_stack.top();
}

void print_truth_table(std::string formula) {
    std::map<char, int> usedVar;
    std::string currentFormula = formula;
    int maxRows = 0;

    for (char c : formula) {
        if (c >= 'A' && c <= 'Z') {
            if (usedVar.count(c) == 0)
                usedVar.insert({c, 0});
        }
    }

    //header
    std::cout << "| ";
    for (const auto& [key, value] : usedVar)
        std::cout << key << " | ";
    std::cout << "= |" << std::endl;
    for (int i = 0; i <= usedVar.size(); i++)
        std::cout << "|---";
    std::cout << "|" << std::endl;

    //fill
    maxRows = power(2, usedVar.size());
    for (int i = 0; i < maxRows; i++) {
        for (const auto& [key, value] : usedVar) {
            std::replace(currentFormula.begin(),currentFormula.end(), key, (char)(value+48));
        }
        std::cout << "| ";
        for (const auto& [key, value] : usedVar)
            std::cout << value << " | ";
        std::cout << eval_formula(currentFormula) << " |" << std::endl;
        currentFormula = formula;
    }
}

int main(void) {
    print_truth_table("AB&C|");
    return 0;
}