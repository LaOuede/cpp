#include <iostream>
#include <string>

using std::cout;
using std::endl;

int main(int argc, char **argv) {

	if (argc == 1) {
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
		return 0 ;
	}

	for (int arg = 1; arg < argc; arg++) {
		std::string str = argv[arg];
		for (std::string::size_type i = 0; i < str.length(); i++) {
			cout << (char)std::toupper(str[i]);
		}
	}

	cout << endl;
	return 0;
}