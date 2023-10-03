#include <iostream> // std::cout, std::endl
#include <iomanip> // std::setw
#include <string>
#include "Phonebook.hpp"

void Phonebook::displayInfos( int index ) {
	int	contactToDisplay;

	do {
		std::cout << "Contact to display : ";
		std::cin >> contactToDisplay;
		if (! std::cin.fail() && contactToDisplay >= 0 && contactToDisplay <= index) {
			_m_contacts[contactToDisplay].displayContact();
			return ;
		}
		else {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		}
	} while (! std::cin.fail());
}

void Phonebook::addContact ( int index ) {
	std::cout << "index : " << index << std::endl;
	_m_contacts[index].setContact();
}

void Phonebook::searchContact ( int index ) {

	std::cout << "*--------------📞 PHONEBOOK 📞--------------*" << std::endl;
	std::cout << "|  " << C_GRY << "index" << C_WHT << "   | ";
	std::cout << C_GRY << "1st name" << C_WHT << " |   ";
	std::cout << C_GRY << "name" << C_WHT << "   | ";
	std::cout << C_GRY << "nickname" << C_WHT << " |" << std::endl;
	for (int i = 1; i < index; i++) {
		std::cout << "|-------------------------------------------|" << std::endl;
		std::cout << "|" << std::setw(10) << i << "|";
		std::cout << std::setw(10) << _m_contacts[i].getInfos("firstName") << "|";
		std::cout << std::setw(10) << _m_contacts[i].getInfos("lastName") << "|";
		std::cout << std::setw(10) << _m_contacts[i].getInfos("nickname") << "|" << std::endl;
	}
	std::cout << "*-------------------------------------------*" << std::endl;
	displayInfos(index);
}

Phonebook::Phonebook( void ) {
	std::cout << C_GRY << "Phonebook has been created" << C_WHT << std::endl;
	return;
}

Phonebook::~Phonebook( void ) {
	std::cout << C_GRY << "Phonebook has been destroyed" << C_WHT << std::endl;
	return;
}
