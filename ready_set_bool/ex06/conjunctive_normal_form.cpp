#include "../utils/tree.h"
#include <vector>

//I can't use the existing NNF function due to the subject limitations.
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

Node* toCNF(Node* node) {
	if (node == nullptr) return nullptr;

	if (isVariable(node->value) || node->value == '!')
		return node;

	if (node->value == '&')
		return createNodeWithValues('&', toCNF(node->left), toCNF(node->right));

	if (node->value == '|') {
		Node* A = toCNF(node->left);
		Node* B = toCNF(node->right);

		if (A->value == '&' || B->value == '&') {
			if (A->value == '&' && B->value == '&') {
				Node* c1 = createNodeWithValues('|', A->left, B->left);
				Node* c2 = createNodeWithValues('|', A->left, B->right);
				Node* c3 = createNodeWithValues('|', A->right, B->left);
				Node* c4 = createNodeWithValues('|', A->right, B->right);
				Node* and1 = createNodeWithValues('&', c1, c2);
				Node* and2 = createNodeWithValues('&', c3, c4);
				return createNodeWithValues('&', and1, and2);
			}
			else if (A->value == '&') {
				Node* c1 = createNodeWithValues('|', A->left, B);
				Node* c2 = createNodeWithValues('|', A->right, B);

				return createNodeWithValues('&', c1, c2);
			}
			else {
				Node* c1 = createNodeWithValues('|', B, A->left);
				Node* c2 = createNodeWithValues('|', B, A->right);

				return createNodeWithValues('&', c1, c2);
			}
		}
		else
			return createNodeWithValues('|', A, B);
	}
	return nullptr;
}

void collectOperands(Node* node, char op, std::vector<Node*>& out) {
	if (!node) return;

	if (node->value == op) {
		collectOperands(node->left, op, out);
		collectOperands(node->right, op, out);
	} else
		out.push_back(node);
}

void fromTreeToStr(Node* node, std::string &formula) {
	if (!node) return;

	if (node->value == '&' || node->value == '|') {
		std::vector<Node*> operands;
		collectOperands(node, node->value, operands);
		for (Node* operand : operands)
			fromTreeToStr(operand, formula);
		for (size_t i = 1; i < operands.size(); ++i)
			formula += node->value;
	}
	else {
		fromTreeToStr(node->left, formula);
		fromTreeToStr(node->right, formula);
		formula += node->value;
	}
}


std::string conjunctive_normal_form(std::string formula) {
	std::string result;

	Node* treeNNF = toNNF(treeBuilder(formula));
	Node* treeCNF = toCNF(treeNNF);
	fromTreeToStr(treeCNF, result);

	return result;
}

int main(void) {
	std::cout << conjunctive_normal_form("AB&!") << std::endl;
	std::cout << conjunctive_normal_form("AB|!") << std::endl;
	std::cout << conjunctive_normal_form("AB|C&") << std::endl;
	std::cout << conjunctive_normal_form("AB|C|D|") << std::endl;
	std::cout << conjunctive_normal_form("AB&C&D&") << std::endl;
	std::cout << conjunctive_normal_form("AB&!C!|") << std::endl;
	std::cout << conjunctive_normal_form("AB|!C!&") << std::endl;
	return 0;
}