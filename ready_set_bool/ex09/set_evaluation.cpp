#include <iostream>
#include <vector>
#include "../utils/utils.h"

std::vector<int> eval_set(std::string formula, std::vector<std::vector<int>> sets) {
    std::vector<int> result;

    result.insert(1 & 1);

    return result;
}


int main(void) {
    std::vector<int> result;
    std::vector<std::vector<int>> sets = {
        {0, 1, 2},
        {0, 3, 4},
    };



    result = eval_set("AB&", sets);
    for (int i : result)
        std::cout << i << std::endl;
    return 0;
}