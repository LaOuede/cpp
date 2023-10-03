#include <iostream>
#include <string>
#include "Phonebook.hpp"

void Phonebook::addContact ( ) {
	indiv.setContact();
}

Phonebook::Phonebook( void ) {
	std::cout << C_GRY << "Phonebook has been created" << C_WHT << std::endl;
	return;
}

Phonebook::~Phonebook( void ) {
	std::cout << C_GRY << "Phonebook has been destroyed" << C_WHT << std::endl;
	return;
}
