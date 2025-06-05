#include <iostream>
#include <cstdlib>
#include <ctime>

unsigned int adder(unsigned int a, unsigned int b) {
    unsigned int carry;
    while (b != 0) {
        carry = (a & b) << 1;
        a = a ^ b;
        b = carry;
    }
    return a;
}

unsigned int multiplier(unsigned int a, unsigned int b) {
    unsigned int result = 0;
    while (b != 0) {
        if (b & 1)
            result = adder(result, a);
        a <<= 1;
        b >>= 1;
    }
    return result;
}

int main(void) {
    srand((unsigned)time(0));
    for (int i = 0; i < 5; i++) {
        unsigned int a = rand() % 11;
        unsigned int b = rand() % 11;
        std::cout << "the sum of " << a << " and " << b << " is " << multiplier(a, b) << std::endl;
    }
    return 0;
}
