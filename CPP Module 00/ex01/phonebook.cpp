#include <iostream>
#include <string>
#include "Phonebook.hpp"

Phonebook::Phonebook( void ) {
	std::cout << "Phonebook has been created" << std::endl;
	return;
}

Phonebook::~Phonebook( void ) {
	std::cout << "Phonebook has been destroyed" << std::endl;
	return;
}
