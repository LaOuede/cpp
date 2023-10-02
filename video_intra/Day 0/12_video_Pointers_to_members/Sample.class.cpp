#include <iostream>
#include "Sample.class.hpp"

Sample::Sample( void ) : m_Foo( 0 ) {
	std::cout << "Constructor called" << std::endl;
	return;
}

Sample::~Sample( void ) {
	std::cout << "Destructor called" << std::endl;
	return;
}

void Sample::Bar( void ) const {
	std::cout << "Member fucntion bar called" << std::endl;
	return;
}