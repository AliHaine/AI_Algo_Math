#ifndef UTILS_HPP
#define UTILS_HPP

using std::cout;
using std::endl;
using std::initializer_list;
#include <iostream>

void fatalError(const char* msg) {
	std::cout << "FATAL ERROR: " << msg << std::endl;
	exit(1);
}

#endif
