#include "negation_normal_form.h"

Node* toNNF(Node* node) {
	if (node == nullptr) return nullptr;

	if (node->value == '!') {
		Node* child = node->left;

		if (child->value == '!')
			return toNNF(child->left);

		if (child->value == '&' || child->value == '|') {
			Node* a = toNNF(createNodeWithValues('!', child->left, nullptr));
			Node* b = toNNF(createNodeWithValues('!', child->right, nullptr));
			char op = (child->value == '&') ? '|' : '&';
			return createNodeWithValues(op, a, b);
		}
		return createNodeWithValues('!', toNNF(child), nullptr);
	}

	if (node->value == '>') {
		Node* notA = toNNF(createNodeWithValues('!', node->left, nullptr));
		Node* B = toNNF(node->right);
		return createNodeWithValues('|', notA, B);
	}

	if (node->value == '=') {
		Node* A = toNNF(node->left);
		Node* B = toNNF(node->right);

		Node* notA = toNNF(createNodeWithValues('!', node->left, nullptr));
		Node* notB = toNNF(createNodeWithValues('!', node->right, nullptr));

		Node* aAndB = createNodeWithValues('&', A, B);
		Node* naAndnB = createNodeWithValues('&', notA, notB);
		return createNodeWithValues('|', aAndB, naAndnB);
	}

	if (node->value == '&' || node->value == '|') {
		Node* left = toNNF(node->left);
		Node* right = toNNF(node->right);
		return createNodeWithValues(node->value, left, right);
	}

	return node;
}

void from_tree_to_str(Node* node, std::string &formula) {
	if (!node) return;
	from_tree_to_str(node->left, formula);
	from_tree_to_str(node->right, formula);
	formula += node->value;
}

std::string negation_normal_form(std::string formula) {
    std::string convertedFormula;
	Node* converted = toNNF(treeBuilder(formula));
	from_tree_to_str(converted, convertedFormula);
    return convertedFormula;
}

int main(void) {

    std::cout << negation_normal_form("AB&!") << std::endl; // A!B!|
    std::cout << negation_normal_form("AB|!") << std::endl; // A!B!&
    std::cout << negation_normal_form("AB>") << std::endl; // A!B|
    std::cout << negation_normal_form("AB=") << std::endl; // AB&A!B!&|
    std::cout << negation_normal_form("AB|C&!") << std::endl; // A!B!&C!|

    std::cout << negation_normal_form("AB|C&Z&!") << std::endl; //A!B!&C!|Z!|
	std::cout << negation_normal_form("AB|C&!Z&!") << std::endl;

    return 0;
}