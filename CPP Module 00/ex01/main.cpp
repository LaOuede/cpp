#include <iostream> // std::cout, std::endl
#include <iomanip> // std::setw
#include <string>
#include "Phonebook.hpp"
#include "Contact.hpp"

int main( void ) {
	Phonebook phonebook;
	std::string cmd;
	int index = 1;

	std::cout << std::endl;
	std::cout << C_BOL << "--- Welcome to 📞 Phonebook 📞 ---\n" << C_WHT << std::endl;

	while (index < 9) {
		std::cout << "🔵 -> ";
		std::cin >> cmd;
		if (cmd == "ADD") {
			//std::cout << "command ADD selected" << std::endl;
			phonebook.addContact(index);
			index ++;
		}
		else if (cmd ==  "SEARCH"){
			//std::cout << "command SEARCH selected" << std::endl;
			phonebook.searchContact(index);
		}
		else if (cmd == "EXIT") {
			std::cout << C_BOL << "\n------- quitting program... ------\n" << std::endl;
			return 0;
		}
		if (index == 8)
			index = 0;
	}
	return 0;
}