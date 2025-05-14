#include <iostream>
#include <functional>
#include <unordered_map>
#include <stack>

std::stack<char> mainStack;

bool isVariable(char c) {
    return (c >= 'A' && c <= 'Z');
}

bool isOperator(char c) {
    return c == '&' || c == '>' || c == '|';
}

void isValid(std::string formula) {
    std::stack<int> test_stack;
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
        if (c == '!')
            continue;
        if (isVariable(c)) {
            test_stack.push('0');
            continue;
        }
        if (!operator_map.count(c) || test_stack.size() < 2) {
            std::cout << std::endl << "An error occurred with your formula, please check it (size)" << std::endl;
            exit(1);
        }
        a = test_stack.top(); test_stack.pop();
        b = test_stack.top(); test_stack.pop();
        test_stack.push(operator_map[c](a, b));
    }
    if (test_stack.size() != 1) {
        std::cout << std::endl << "An error occurred with your formula, please check it (remind)" << std::endl;
        exit(1);
    }
}

void negatParsing(void) {
    std::stack<char> tmpStack;
    char current;
    char prevCurrent;

    tmpStack.push(mainStack.top() == '&' ? '|' : '&');
    mainStack.pop();

    for (int i = 0; i < 2; i++) {
        current = mainStack.top();
        if (isVariable(current)) {
            tmpStack.push('!');
            tmpStack.push(current);
            mainStack.pop();
        } else {
            i = -1;
            mainStack.pop();
            prevCurrent = mainStack.top();
            if (prevCurrent == '!') {
                tmpStack.push(current);
                break;
            }
            tmpStack.push(current == '&' ? '|' : '&');
        }
    }

    while(!tmpStack.empty()) {
        mainStack.push(tmpStack.top());
        tmpStack.pop();
    }
}

std::string negation_normal_form(std::string formula) {
    std::string convertedFormula;
    std::unordered_map<char, std::function<void(char a, char b)>> convertor_map = {
        {'&', [](char a, char b) {
            mainStack.push(a);
            mainStack.push(b);
            mainStack.push('&');
        }},
        {'|', [](char a, char b) {
            mainStack.push(a);
            mainStack.push(b);
            mainStack.push('|');
        }},
        {'>', [](char a, char b) {
            mainStack.push(a);
            mainStack.push('!');
            mainStack.push(b);
            mainStack.push('|');
        }},
        {'=', [](char a, char b) {
            mainStack.push(a);
            mainStack.push(b);
            mainStack.push('&');
            mainStack.push(a);
            mainStack.push('!');
            mainStack.push(b);
            mainStack.push('!');
            mainStack.push('&');
            mainStack.push('|');
        }}
    };

    //isValid(formula);

    char a;
    char b;
    for (char c : formula) {
        if (isVariable(c)) {
            mainStack.push(c);
            continue;
        } else if (convertor_map.count(c)) {
            b = mainStack.top(); mainStack.pop();
            a = mainStack.top(); mainStack.pop();
            convertor_map[c](a, b);
            continue;
        } else if (c == '!') {
            if (isVariable(mainStack.top())) {
                mainStack.push('!');
            } else if (mainStack.top() == '&' || mainStack.top() == '|') {
                negatParsing();
            }
        } else {
            std::cout << "An error occurred with your formula, please check it." << std::endl;
            exit(1);
        }
    }

    while(!mainStack.empty()) {
        convertedFormula.insert(0, 1, mainStack.top());
        mainStack.pop();
    }

    return convertedFormula;
}


int main(void) {

    /*std::cout << negation_normal_form("AB&!") << std::endl;;
    // A!B!|
    std::cout << negation_normal_form("AB|!") << std::endl;;
    // A!B!&
    std::cout << negation_normal_form("AB>") << std::endl;;
    // A!B|
    std::cout << negation_normal_form("AB=") << std::endl;;
    // AB&A!B!&|
    std::cout << negation_normal_form("AB|C&!") << std::endl;;
    // A!B!&C!|

    std::cout << negation_normal_form("AB|C&Z&!") << std::endl;*/

    //std::cout << negation_normal_form("AB|C&!Z&!") << std::endl;

    //std::cout << negation_normal_form("AB&C!") << std::endl;

    //std::cout << negation_normal_form("AB|C&!Z&!") << std::endl;

    //std::cout << negation_normal_form("AB>C!") << std::endl;


    return 0;
}