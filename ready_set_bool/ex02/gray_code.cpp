#include <iostream>

int gray_code(int number) {
    return number;
}

int main(void) {
    for (int i = 0; i < 100; i++)
        std::cout << gray_code(i) << std::endl;
    return 0;
}
