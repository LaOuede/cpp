#include <iostream>
#include <string>
#include "Phonebook.hpp"
#include "Contact.hpp"

int main( void ) {
	Phonebook phonebook;
	std::string cmd;

	std::cout << "--- Welcome to 📞 Phonebook 📞 ---" << std::endl;
	std::cout << "-> ";
	std::cin >> cmd;

	if (cmd == "ADD") {
		std::cout << "command ADD selected" << std::endl;
		phonebook.addContact();
	}
	else if (cmd ==  "SEARCH") {
		std::cout << "command SEARCH selected" << std::endl;
	}
	else {
		std::cout << "quiting program..." << std::endl;
		exit (0);
	}

	return 0;
}