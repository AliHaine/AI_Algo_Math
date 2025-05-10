#include <list>
#include <iostream>
#include <stack>

std::list<char> usedVar;
std::list<char> allowedOperators = {'&', '|', '^', '=', '>'};

bool already_used(char letter) {
    for (char c : usedVar) {
        if (c == letter)
            return true;
    }
    return false;
}

bool is_allowed_operator(char op) {
    for (char c : allowedOperators) {
        if (c == op)
            return true;
    }
    return false;
}

void print_truth_table(std::string formula) {
    std::stack<int> main_stack;

    for (char c : formula) {
        if (c >= 'A' && c <= 'Z' && !already_used(c)) {
            usedVar.push_front(c);
            main_stack.push(0);
            continue;
        }
        if (!is_allowed_operator(c)) {
            std::cout << "The character " << c " is not allowed here" << std::endl;
            exit(1);
        }
        main_stack.pop();
        main_stack.pop();
        main_stack.push(0);
    }

    for (char c : usedVar) {
        std::cout << c << std::endl;
    }
}

int main(void) {
    print_truth_table("ABCDA");
    return 0;
}