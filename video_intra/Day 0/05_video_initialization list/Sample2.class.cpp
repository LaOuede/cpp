#include <iostream>
#include "Sample2.class.hpp"

Sample2::Sample2( char p1, int p2, float p3 ) : m_a1(p1), m_a2(p2), m_a3(p3) {

	std::cout << "Constructor called" << std::endl;
	std::cout << "this->m_a1: " << this->m_a1 << std::endl;
	std::cout << "this->m_a2: " << this->m_a2 << std::endl;
	std::cout << "this->m_a3: " << this->m_a3 << std::endl;

	return;
}

Sample2::~Sample2( void ) {

	std::cout << "Destructor called" << std::endl;
	return;
}