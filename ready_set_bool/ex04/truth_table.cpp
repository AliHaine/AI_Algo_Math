#include <iostream>
#include <map>
#include <algorithm>
#include "../utils/tree.h"

void print_header(std::map<char, int> &usedVar) {
    std::cout << "| ";
    for (auto it = usedVar.begin(); it != usedVar.end(); ++it)
        std::cout << it->first << " | ";
    std::cout << "= |" << std::endl;
    for (int i = 0; i <= usedVar.size(); i++)
        std::cout << "|---";
    std::cout << "|" << std::endl;
}

void print_truth_table(std::string formula) {
    std::map<char, int> usedVar;
    std::string currentFormula = formula;
    int maxRows;

    for (char c : formula) {
		if (c == '0' || c == '1') {
			std::cout << "The formula " << formula << " is not valid" << std::endl;
			exit(1);
		}
        if (c >= 'A' && c <= 'Z') {
            if (usedVar.count(c) == 0)
                usedVar.insert({c, 0});
        }
    }

    print_header(usedVar);

    maxRows = power(2, usedVar.size());
    // Build formula
    for (int i = 0; i < maxRows; i++) {
        for (auto it = usedVar.rbegin(); it != usedVar.rend(); ++it) {
            if (i == 0)
                break;
            if (it->second == 0) {
                it->second = 1;
                while (it-- != usedVar.rbegin())
                    it->second = 0;
                break;
            }
        }
        for (auto it = usedVar.begin(); it != usedVar.end(); ++it)
            std::replace(currentFormula.begin(),currentFormula.end(), it->first, (char)(it->second+48));
        std::cout << "| ";

        for (auto it = usedVar.begin(); it != usedVar.end(); ++it)
            std::cout << it->second << " | ";
        std::cout << calcFromTree(treeBuilder(currentFormula, false)) << " |" << std::endl;
        currentFormula = formula;
    }
}

int main(void) {
    print_truth_table("A!");
    std::cout << "------------------------------" << std::endl;
    print_truth_table("AB!=");
    std::cout << "------------------------------" << std::endl;
    print_truth_table("AB=");
    std::cout << "------------------------------" << std::endl;
    print_truth_table("AB=C&");
    std::cout << "------------------------------" << std::endl;
    print_truth_table("AB=C&A|");
    return 0;
}