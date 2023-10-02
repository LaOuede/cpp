#include <iostream>
#include "Sample1.class.hpp"

Sample1::Sample1( char p1, int p2, float p3 ) {

	std::cout << "Constructor called" << std::endl;

	this->m_a1 = p1;
	std::cout << "this->m_a1: " << this->m_a1 << std::endl;

	this->m_a2 = p2;
	std::cout << "this->m_a2: " << this->m_a2 << std::endl;

	this->m_a3 = p3;
	std::cout << "this->m_a3: " << this->m_a3 << std::endl;

	return;
}

Sample1::~Sample1( void ) {

	std::cout << "Destructor called" << std::endl;
	return;
}