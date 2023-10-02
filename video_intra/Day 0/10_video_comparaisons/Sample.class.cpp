#include <iostream>
#include "Sample.class.hpp"

Sample::Sample( int v ) : _m_Foo( v ) {
	std::cout << "Constructor called" << std::endl;
	return;
}

Sample::~Sample( void ) {
	std::cout << "Destructor called" << std::endl;
	return;
}

int Sample::getFoo( void ) const {
	return this->_m_Foo;
}

int Sample::compare( Sample *other ) const {
	if ( this->_m_Foo < other->getFoo() )
		return -1;
	else if ( this->_m_Foo > other->getFoo() )
		return 1;
	return 0;
}