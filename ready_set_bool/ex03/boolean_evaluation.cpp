#include <iostream>
#include "../utils/tree.h"
#include <list>

void tests_simple();
void tests_complex();

bool eval_formula(std::string formula) {
    return calcFromTree(treeBuilder(formula, false));
}

int main(void) {
    tests_simple();
    //tests_complex();
    return 0;
}

void tests_simple() {
    std::list<std::string> formulas = {
            "0!", "1!",        // NEGATE
            "10&", "11&",      // AND
            "10|", "00|",      // OR
            "10^", "11^",      // XOR
            "11=", "01=",      // EQUAL
            "10>", "01>", "11>", "00>", // IMPLICATION
            "10|!", "10>!1="   // Complex expressions
    };

    for (const auto& formula : formulas)
        std::cout << "Result for formula " << formula << " = " << eval_formula(formula) << std::endl;
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