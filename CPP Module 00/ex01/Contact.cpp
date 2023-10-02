#include <iostream>
#include <string>
#include "Contact.hpp"

void Contact::setContact( void ) {
	std::cout << "First name : ";
	std::cin >> _m_firstName;
	std::cout << "Last name : ";
	std::cin >> _m_lastName;
	std::cout << "Nickname : ";
	std::cin >> _m_nickname;
	std::cout << "Phone Number : ";
	std::cin >> _m_phoneNumber;
	std::cout << "Darkest secret : ";
	std::cin >> _m_darkestSecret;
	std::cout << C_GRY << "First name : " << _m_firstName << std::endl;
	std::cout << "Last name : " << _m_lastName << std::endl;
	std::cout << "Nickname : " << _m_nickname << std::endl;
	std::cout << "Phone Number : " << _m_phoneNumber << std::endl;
	std::cout << "Darkest secret : " << _m_darkestSecret << C_WHT << std::endl;
}

Contact::Contact( void ) {
	std::cout << C_GRY << "Contact has been created" << C_WHT << std::endl;
	return;
}

Contact::~Contact( void ) {
	std::cout << C_GRY << "Contact has been destroyed" << C_WHT << std::endl;
	return;
}
