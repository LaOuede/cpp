#include <iostream> // std::cout, std::endl
#include <iomanip> // std::setw
#include <string>
#include "Contact.hpp"

using std::cin;
using std::cout;
using std::endl;

std::string Contact::reSize( std::string str ) {
	std::string new_str;

	new_str = str.substr(0, 9);
	new_str.insert(new_str.end(), '.');
	return (new_str);
}

std::string Contact::getInfos( std::string element ) {
	if (element == "firstName") {
		if (_m_firstName.size() > 10)
			return (reSize( _m_firstName));
		return (_m_firstName);
	}
	else if (element == "lastName"){
		if (_m_lastName.size() > 10)
			return (reSize( _m_lastName));
		return (_m_lastName);
	}
	else if (element == "nickname"){
		if (_m_nickname.size() > 10)
			return (reSize( _m_nickname));
		return (_m_nickname);
	}
	return 0;
}

void Contact::displayContact( void ) {
	cout << C_BLU << "\n----- Contact informations -----" << C_WHT << endl;
	cout << "First name : " << _m_firstName << endl;
	cout << "Last name : " << _m_lastName << endl;
	cout << "Nickname : " << _m_nickname << endl;
	cout << "Phone Number : " << _m_phoneNumber << endl;
	cout << "Darkest secret : " << _m_darkestSecret << endl;
	cout << C_BLU << "------------- end --------------\n" << C_WHT << endl;
}

void Contact::setContact( void ) {
	cout << C_BLU << "\n----- Complete informations ------" << C_WHT << endl;
	cout << "First name : ";
	cin >> _m_firstName;
	cout << "Last name : ";
	cin >> _m_lastName;
	cout << "Nickname : ";
	cin >> _m_nickname;
	cout << "Phone Number : ";
	cin >> _m_phoneNumber;
	cout << "Darkest secret : ";
	cin >> _m_darkestSecret;
	cout << C_BLU << "--------- Contact saved! ---------\n" << C_WHT << endl;
}

Contact::Contact( void ) {
	static int index = 0;
	std::cout << C_GRY << "Contact " << index << " has been created" << C_WHT << std::endl;
	index++;
	return;
}

Contact::~Contact( void ) {
	static int index = 8;
	std::cout << C_GRY << "Contact " << index << " has been destroyed" << C_WHT << std::endl;
	index--;
	return;
}
