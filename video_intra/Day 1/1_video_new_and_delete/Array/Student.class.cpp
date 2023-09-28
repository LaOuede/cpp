#include <iostream>
#include "Student.class.hpp"

Student::Student( void ) : _login("ldefault") {
	std::cout << "Student " << this->_login << " is born" << std::endl;
	return;
}

Student::~Student( void ) {
	std::cout << "Student " << this->_login << " died" << std::endl;
	return;
}