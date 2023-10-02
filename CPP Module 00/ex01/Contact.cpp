#include <iostream>
#include <string>
#include "Contact.hpp"

Contact::Contact( void ) {
	std::cout << "Contact has been created" << std::endl;
	return;
}

Contact::~Contact( void ) {
	std::cout << "Contact has been destroyed" << std::endl;
	return;
}
