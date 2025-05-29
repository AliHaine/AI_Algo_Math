#include "../ex05/negation_normal_form.h"

Node* toCNF(Node* node) {
	if (node == nullptr) return nullptr;

	if (isVariable(node->value))
		return node;

	if (node->value == '&')
		return createNodeWithValues('&', toCNF(node->left), toCNF(node->right));

	if (node->value == '|') {
		Node* A_cnf = toCNF(node->left);
		Node* B_cnf = toCNF(node->right);

		if (A_cnf->value == '&' || B_cnf->value == '&') {
			//todo
			return distribute_OR_over_AND(A_cnf, B_cnf);
		}
		else
			return createNodeWithValues('|', A_cnf, B_cnf);
	}
	return nullptr;
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