#include <iostream>
#include <stack>
#include <functional>
#include <unordered_map>
#include "../utils/utils.h"

void tests_simple();
void tests_complex();
void tests_error();

bool eval_formula(std::string formula) {
    return calcFromTree(treeBuilder(formula));
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