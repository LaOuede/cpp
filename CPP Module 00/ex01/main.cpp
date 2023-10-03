#include <iostream>
#include <string>
#include "Phonebook.hpp"
#include "Contact.hpp"

int main( void ) {
	Phonebook phonebook;
	std::string cmd;
	int index = 0;

	std::cout << "--- Welcome to 📞 Phonebook 📞 ---" << std::endl;

	while (index < 8) {
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
			std::cout << "quiting program..." << std::endl;
			exit (0);
		}
		if (index == 7)
			index = 0;
	}
	return 0;
}