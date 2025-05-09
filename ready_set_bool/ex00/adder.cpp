#include <iostream>
#include <cstdlib>
#include <bitset>
#include <time.h>

int adder(unsigned int a, unsigned int b) {
    unsigned int carry;
    while (b != 0) {
        carry = (a & b) << 1;
        a = a ^ b;
        b = carry;
    }
    return a;
}

int main(void) {
    srand((unsigned)time(NULL));
    for (int i = 0; i < 5; i++) {
        unsigned int a = rand() % 101;
        unsigned int b = rand() % 101;
        std::cout << "the sum of " << a << " and " << b << " is " << adder(a, b) << std::endl;
    }
    return 0;
}
