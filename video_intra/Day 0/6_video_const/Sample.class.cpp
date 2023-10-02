#include <iostream>
#include "Sample.class.hpp"

Sample::Sample( float const f ) : m_pi( f ), m_qd( 42 ) {

	std::cout << "Constructor called" << std::endl;

	return;
}

Sample::~Sample( void ) {

	std::cout << "Destructor called" << std::endl;
	return;
}

void Sample::bar( void ) const {

	std::cout << "this->m_pi = " << this->m_pi << std::endl;
	std::cout << "this->m_qd = " << this->m_qd << std::endl;

	//this->qd = 0;
}