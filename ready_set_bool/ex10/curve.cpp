#include <iostream>
#include <iomanip>
#include <ctime>

double map(unsigned short x, unsigned short y) {
	std::cout << "Inputs: " << "X: "<< x << " Y: " << y << std::endl;
	unsigned int z = x << 16 | y;
	std::cout << "Z-value: " << z << std::endl;
	return z / 4294967295.0f;
}

int main(void) {
	std::cout << std::fixed << std::setprecision(32) << map(1414, 2728) << std::endl;

	srand((unsigned)time(0));
	for (int i = 0; i < 5; i++) {
		std::cout << std::fixed << std::setprecision(11) << map(rand()%10000, rand()%10000) << std::endl;
		std::cout << "-------------" << std::endl;
	}
	std::cout << std::fixed << std::setprecision(11) << map(5, 5) << std::endl;
	std::cout << std::fixed << std::setprecision(11) << map(5, 5) << std::endl;
	std::cout << "-------------" << std::endl;
	return 0;
}