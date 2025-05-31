#include "../utils/set_tree.h"

std::vector<int> calcFromTree(Node* node) {
	if (node->op != 0)
		return vectorOperators[node->op](calcFromTree(node->left), calcFromTree(node->right));
	return node->values;
}

std::vector<int> eval_set(std::string formula, std::vector<std::vector<int>> &sets) {
    std::vector<int> result;

    Node* tree = treeBuilder(formula, sets);
	postOrder(tree);

	return calcFromTree(tree);
}

int main(void) {
    std::vector<int> result;
    std::vector<std::vector<int>> sets = {
        {0, 1, 2},
        {0, 1, 2,4},
    };

    result = eval_set("AB=", sets);
    for (int i : result)
        std::cout << i;
    return 0;
}