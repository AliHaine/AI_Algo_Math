#include <iostream>
#include <utility>

std::pair<unsigned short, unsigned short> reverse_map(double n) {
	unsigned int z = n * 4294967295.0f;
	return std::make_pair(z >> 16,  z & 0xFFFF);
}

int main(void) {
	auto res = reverse_map(0.02157656289637088775634765625000); // 1414 Y: 2728
	std::cout << res.first << " " << res.second << std::endl;

	res = reverse_map(0.0004);
	std::cout << res.first << " " << res.second << std::endl;
	res = reverse_map(0.0004);
	std::cout << res.first << " " << res.second << std::endl;
	std::cout << "-------------" << std::endl;
	return 0;
}