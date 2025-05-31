#include "../utils/set_tree.h"

std::vector<int> u = {};

std::vector<int> calcFromTree(Node* node) {
	if (node->op == '!')
		return vectorOperators[node->op](u, calcFromTree(node->left));
	else if (node->op != 0)
		return vectorOperators[node->op](calcFromTree(node->left), calcFromTree(node->right));
	return node->values;
}

std::vector<int> eval_set(std::string formula, std::vector<std::vector<int>> &sets) {
    std::vector<int> result;
	u = {};
	for (auto &set : sets)
		u = vectorOperators['|'](u, set);
    Node* tree = treeBuilder(formula, sets);
	return calcFromTree(tree);
}

void printResult(std::vector<int> result) {
	std::cout << '[';
	for (size_t i = 0; i < result.size(); ++i) {
		std::cout << result[i];
		if (i + 1 < result.size())
			std::cout << ", ";
	}
	std::cout << ']' << std::endl;
}

void tests() {
	std::vector<std::vector<int>> sets = {
			{0, 1, 2},
			{0, 3, 4},
	};
	printResult(eval_set("AB&", sets));
	sets = {
			{0, 1, 2},
			{3, 4, 5},
	};
	printResult(eval_set("AB|", sets));
	sets = {
			{0, 1, 2},
	};
	printResult(eval_set("A!", sets));
}

void testsMore(){
	std::vector<std::vector<int>> sets = {
			{0, 1, 2, 3},
			{4, 5, 6, 7},
			{11, 13, 15}
	};

	printResult(eval_set("AB|", sets));
	printResult(eval_set("AB&", sets));
	printResult(eval_set("AB^", sets));
	printResult(eval_set("AB=", sets));
	sets = {
			{0, 1, 2, 3},
			{0, 1, 2, 3},
	};
	printResult(eval_set("AB=", sets));
}

void testsComplex() {
	std::vector<std::vector<int>> sets = {
			{0, 1, 2, 3},
			{4, 5, 6, 7},
			{11,13,15},
			{25,26,28}
	};

	printResult(eval_set("AB|CD||", sets));
	// = (¬A ∪ B) ∩ (¬A ∪ C)
	// From earlier:
	// (¬A ∪ B) = {4,5,6,7,11,13,15}
	// (¬A ∪ C) = {4,5,6,7,11,13,15}
	// ∩ gives same: {4,5,6,7,11,13,15}
	/*printResult(eval_set("AB=C>", sets));*/
	// Evaluate (B = C), then A > that result
	// B = {4,5,6,7}, C = {11,13,15} → B=C is false → result = {}
	// Then: A > {} → (U \ A) ∪ {} = {4,5,6,7,11,13,15}
}

int main(void) {
    std::vector<std::vector<int>> sets = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
		{11,13,15}
    };

	//tests();
	//testsMore();
	testsComplex();
    return 0;
}