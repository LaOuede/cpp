#include <iostream>
#include <string>
#include "Phonebook.hpp"

void Phonebook::addContact ( int index ) {
	std::cout << "index : " << index << std::endl;
	_m_contacts[index].setContact();
}

void Phonebook::searchContact ( int index ) {
	int	contactToDisplay;
	std::cout << "*--------------📞 PHONEBOOK 📞--------------*" << std::endl;
	std::cout << "|  " << C_GRY << "index" << C_WHT << "   | " << C_GRY << "1st name" << C_WHT << " |   " << C_GRY << "name" << C_WHT << "   | " << C_GRY << "nickname" << C_WHT << " |" << std::endl;
	for (int i = 0; i < index; i++) {
		std::cout << "*-------------------------------------------*" << std::endl;
		std::cout << "|    " << index << "     | " << _m_contacts[i].getInfos("firstName") << " | " << _m_contacts[i].getInfos("lastName") << " | " << _m_contacts[i].getInfos("nickname") << " |" << std::endl;
	}
	std::cout << "*-------------------------------------------*" << std::endl;
	std::cout << "Index to display : ";
	std::cin >> contactToDisplay;
	_m_contacts[contactToDisplay - 1].displayContact();
}

Phonebook::Phonebook( void ) {
	std::cout << C_GRY << "Phonebook has been created" << C_WHT << std::endl;
	return;
}

Phonebook::~Phonebook( void ) {
	std::cout << C_GRY << "Phonebook has been destroyed" << C_WHT << std::endl;
	return;
}
