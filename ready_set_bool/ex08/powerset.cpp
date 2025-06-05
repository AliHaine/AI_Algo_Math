#include <iostream>
#include <vector>

void printSuperSet(std::vector<std::vector<int>> &superSet) {
    for (const auto& vec : superSet) {
        for (int i : vec)
            std::cout << i << " ";
        std::cout << std::endl;
    }
}

std::vector<std::vector<int>> powerset(std::vector<int> &set) {
    auto size = set.size();
    std::vector<std::vector<int>> result = {};

    for (int i = 0; i < (1 << size); i++) {
        std::vector<int> currentSet;
        for (int j = 0; j < size; j++)
            if (i & (1 << j)) currentSet.push_back(set[j]);
        result.push_back(currentSet);
    }
    return result;
}

int main(void) {
    std::vector<int> set = {1, 2, 3, 4};
    std::vector<std::vector<int>> res = powerset(set);
    printSuperSet(res);
    return 0;
}