#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

void fatalError(const char* msg) {
	std::cout << "FATAL ERROR: " << msg << std::endl;
	exit(1);
}

#endif
