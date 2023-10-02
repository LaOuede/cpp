#include <iostream>
#include "Student.class.hpp"

Student::Student( void ) : _m_login("ldefault") {
	std::cout << "Student " << this->_m_login << " is born" << std::endl;
	return;
}

Student::~Student( void ) {
	std::cout << "Student " << this->_m_login << " died" << std::endl;
	return;
}