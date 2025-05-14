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
            char top = mainStack.top(); mainStack.pop();
            if (!isVariable(mainStack.top())) {
                mainStack.push(top);
                mainStack.push('!');
            } else if (top == '&' || top == '|') {
                char right = mainStack.top(); mainStack.pop();
                char left = mainStack.top(); mainStack.pop();

                mainStack.push(left);
                mainStack.push('!');
                mainStack.push(right);
                mainStack.push('!');
                mainStack.push(top == '&' ? '|' : '&');
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
    std::cout << negation_normal_form("AB|C&!") << std::endl;

    return 0;
}