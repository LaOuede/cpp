#include <iostream> // std::cout, std::cin, std::endl
#include <iomanip> // std::setw
#include <string>
#include "Phonebook.hpp"
#include "Contact.hpp"

using std::cin;
using std::cout;
using std::endl;

int main( void ) {
	Phonebook phonebook;
	std::string cmd;

	cout << endl;
	cout << C_BOL << "--- 🟢 Welcome to 📞 Phonebook 📞 ---\n" << C_WHT << endl;

	do {
		cout << "🔵 Phonebøøk$ ";
		cin >> cmd;
		if (cmd ==  "SEARCH")
			phonebook.searchContact();
		else if (cmd == "ADD")
			phonebook.addContact();
	} while (! cin.fail() && cmd != "EXIT");
	cout << C_BOL << "\n------- 🔴 quitting program... ------\n" << C_WHT << endl;
	return 0;
}