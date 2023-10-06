#include <iostream>
#include "Sample.class.hpp"

Sample::Sample( void ) {

	std::cout << "Constructor called" << std::endl;

	this->m_publicFoo = 0;
	std::cout << "this->publicFoo = " << m_publicFoo << std::endl;
	this->_m_privateFoo = 0;
	std::cout << "this->_m_privateFoo = " << _m_privateFoo << std::endl;

	this->publicBar();
	this->_privateBar();

	return;
}

Sample::~Sample( void ) {
	std::cout << "Destructor called" << std::endl;
	return;
}

void Sample::publicBar( void ) const {
	std::cout << "Member function publicBar called" << std::endl;
	return;
}

void Sample::_privateBar( void ) const {
	std::cout << "Member function _m_privateBar called" << std::endl;
	return;
}