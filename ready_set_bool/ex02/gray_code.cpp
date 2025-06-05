#include <iostream>
#include <ctime>

unsigned int gray_code(unsigned int number) {
    return (number>>1) ^ number;
}

int main(void) {
	srand((unsigned)time(0));
	for (int i = 0; i < 5; i++) {
        unsigned int a = rand() % 101;
        std::cout << "gray code of " << a << " is " << gray_code(a) << std::endl;
    }
    return 0;
}
