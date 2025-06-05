#include <iostream>
#include <map>
#include <algorithm>
#include "../utils/tree.h"

bool sat(std::string formula) {
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
        if (calcFromTree(treeBuilder(currentFormula, false)))
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