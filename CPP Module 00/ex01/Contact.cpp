#include <iostream> // std::cout, std::cin, std::endl
#include <iomanip> // std::setw
#include <string>
#include "Contact.hpp"

using std::cin;
using std::cout;
using std::endl;


/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
Contact::Contact( void ) { }
Contact::~Contact( void ) { }

/* ************************************************************************** */
/* Getters                                                                    */
/* ************************************************************************** */
std::string &Contact::get_firstName ( void ) { return this->_m_firstName; }
std::string &Contact::get_lastName ( void ) { return this->_m_lastName; }
std::string &Contact::get_nickname ( void ) { return this->_m_nickname; }
std::string &Contact::get_phoneNumber ( void ) { return this->_m_phoneNumber; }
std::string &Contact::get_darkestSecret ( void ) { return this->_m_darkestSecret; }