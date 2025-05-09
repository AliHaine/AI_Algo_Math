#include <iostream>

int gray_code(int number) {
    return (number>>1) ^ number;
}

int main(void) {
    for (int i = 0; i < 5; i++) {
        unsigned int a = rand() % 101;
        std::cout << "gray code of " << a << " is " << gray_code(a) << std::endl;
    }
    return 0;
}
