#include  "../libs/vector.hpp"

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

int main() {
	vectorTests();

	return 0;
}
