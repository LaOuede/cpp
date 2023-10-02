#include <iostream>
#include "Sample.class.hpp"

Sample::Sample( void ) {
	std::cout << "Constructor called" << std::endl;
	Sample::_m_nbInst += 1;
	return;
}

Sample::~Sample( void ) {
	std::cout << "Destructor called" << std::endl;
	Sample::_m_nbInst -= 1;
	return;
}

int Sample::getNbInst( void ) {
	return Sample::_m_nbInst;
}

int Sample::_m_nbInst = 0;