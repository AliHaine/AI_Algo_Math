#include <iostream>
#include <functional>
#include <unordered_map>
#include "../utils/tree.h"

std::string negation_normal_form(std::string formula) {
    std::string convertedFormula;

	Node* tree = treeBuilder<char>(formula);

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