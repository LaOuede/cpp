#include <iostream>
#include <string>
#include "phonebook.hpp"

Phonebook::Phonebook(std::string const contacts) : contacts() {
	std::cout << "Phonebook has been created" << std::endl;
	return;
}

Phonebook::~Phonebook( void ) {
	std::cout << "Phonebook has been destroyed" << std::endl;
	return;
}
