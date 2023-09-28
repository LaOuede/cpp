#include <iostream>
#include <string>

int main(int argc, char **argv) {

	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0 ;
	}

	for (int arg = 1; arg < argc; arg++) {
		std::string str = argv[arg];
		for (std::string::size_type i = 0; i < str.length(); i++) {
			std::cout << (char)toupper(str[i]);
		}
	}
	
	std::cout << std::endl;
	return 0;
}