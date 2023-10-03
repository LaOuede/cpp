#include <iostream> // std::cout, std::endl
#include <iomanip> // std::setw
#include <string>
#include "Phonebook.hpp"
#include "Contact.hpp"

int main( void ) {
	Phonebook phonebook;
	std::string cmd;

	std::cout << std::endl;
	std::cout << C_BOL << "--- 🟢 Welcome to 📞 Phonebook 📞 ---\n" << C_WHT << std::endl;

	do {
		std::cout << "🔵 Phonebøøk$ ";
		std::cin >> cmd;
		if (cmd ==  "SEARCH")
			phonebook.searchContact();
		else if (cmd == "ADD")
			phonebook.addContact();
	} while (cmd != "EXIT");
	std::cout << C_BOL << "\n------- 🔴 quitting program... ------\n" << C_WHT << std::endl;
	return 0;
}