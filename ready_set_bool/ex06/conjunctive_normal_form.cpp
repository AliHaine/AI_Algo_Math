#include "../ex05/negation_normal_form.h"

Node* toCNF(Node* node) {
	if (node == nullptr) return nullptr;


	return node;
}

std::string conjunctive_normal_form(std::string formula) {
	std::string result;

	Node* treeNNF = negation_normal_form(formula);
	Node* treeCNF = toCNF(treeNNF);

	return result;
}

int main(void) {

	return 0;
}