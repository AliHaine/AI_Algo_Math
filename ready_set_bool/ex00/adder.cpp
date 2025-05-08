#include <iostream>
#include <cstdlib>

int adder(int a, int b) {
    return a+b;
}

int main(void) {
    for (int i = 0; i < 5; i++) {
        int a = rand() % 101;
        int b = rand() % 101;
        std::cout << "the sum of " << a << " and " << b << " is " << adder(a, b) << std::endl;
    }
    return 0;
}
