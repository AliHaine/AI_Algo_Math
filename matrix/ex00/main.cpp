#include  "../libs/vector.hpp"
#include "../libs/matrix.hpp"

void vectorTests() {
	auto v = Vector<int>::from({1, 2, 3});
	v.print();

	auto v2 = Vector<int>::from({4, 5, 63});
	v2.print();

	v.add(v2);
	v.print();

	v.sub(v2);
	v.print();

	v.scl(2);
	v.print();

	auto vd = Vector<double>::from({1.8, 3.7});
	vd.print();

	vd.scl(2.9);
	vd.print();
}

void matrixTests() {
	auto m = Matrix<int>::from({
		{ 1, 2, 3 },
		{ 10, 5, 3 },
	});
	m.print();

	auto m2 = Matrix<int>::from({
		   { 3, 2, 1 },
		   { 9, 4, 3 },
	});
	m2.print();

	m.add(m2);

	m.print();

	m.scl(2);
	m.print();

	m.sub(m2);
	m.print();
}

int main() {
	vectorTests();
	matrixTests();

	return 0;
}
