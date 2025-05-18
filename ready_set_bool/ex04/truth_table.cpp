#include <list>
#include <iostream>
#include <stack>
#include <functional>
#include <unordered_map>
#include <map>
#include <algorithm>
#include "../utils/utils.h"

void print_header(std::map<char, int> &usedVar) {
    std::cout << "| ";
    for (auto it = usedVar.begin(); it != usedVar.end(); ++it)
        std::cout << it->first << " | ";
    std::cout << "= |" << std::endl;
    for (int i = 0; i <= usedVar.size(); i++)
        std::cout << "|---";
    std::cout << "|" << std::endl;
    for (int i = 0; i <= usedVar.size(); i++)
        std::cout << "| 0 ";
    std::cout << "|" << std::endl;
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

    print_header(usedVar);

    maxRows = power(2, usedVar.size());
    // Build formula
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
        std::cout << "| ";

        for (auto it = usedVar.begin(); it != usedVar.end(); ++it)
            std::cout << it->second << " | ";
        std::cout << calcFromTree(treeBuilder(currentFormula)) << " |" << std::endl;
        currentFormula = formula;
    }
}

int main(void) {
    print_truth_table("AB&C|");
    return 0;
}