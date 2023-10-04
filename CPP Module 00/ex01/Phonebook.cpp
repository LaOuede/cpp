#include <iostream> // std::cout, std::cin, std::endl
#include <iomanip> // std::setw
#include <string>
#include "Phonebook.hpp"

using std::cin;
using std::cout;
using std::endl;

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
Phonebook::Phonebook( void ) : _m_nbContact(0), _m_index(0) {
	std::cout << C_GRY << "Phonebook constructor called" << C_WHT << std::endl;
}

Phonebook::~Phonebook( void ) {
	std::cout << C_GRY << "Phonebook destructor called" << C_WHT << std::endl;
}

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */
void Phonebook::addContact ( void ) {
	if (_m_nbContact <= 7)
		_m_nbContact++;
	setContact(_m_index);
	_m_index++;
	if (_m_index == 8)
		_m_index = 0;
}

void Phonebook::displayContact( int index ) {
	cout << C_BLU << "\n----- Contact informations -----" << C_WHT << endl;
	cout << "First name : " << _m_contacts[index].get_firstName() << endl;
	cout << "Last name : " << _m_contacts[index].get_lastName() << endl;
	cout << "Nickname : " << _m_contacts[index].get_nickname() << endl;
	cout << "Phone Number : " << _m_contacts[index].get_phoneNumber() << endl;
	cout << "Darkest secret : " << _m_contacts[index].get_darkestSecret() << endl;
	cout << C_BLU << "------------- end --------------\n" << C_WHT << endl;
}

void Phonebook::displayInfos( int nbContact ) {
	int	contactToDisplay;

	do {
		cout << "Contact to display : ";
		cin >> contactToDisplay;
		if (! cin.fail() && contactToDisplay > 0 && contactToDisplay <= nbContact) {
			displayContact(contactToDisplay - 1);
			return ;
		}
		else {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			cout << C_RED << "Phonebook : usage : invalid index " << C_WHT << endl;
		}
	} while (! cin.fail());
}

void Phonebook::displayTab( void ) {
	cout << "\n*--------------📞 PHONEBOOK 📞--------------*" << endl;
	cout << "|  " << C_GRY << "index" << C_WHT << "   | ";
	cout << C_GRY << "1st name" << C_WHT << " |   ";
	cout << C_GRY << "name" << C_WHT << "   | ";
	cout << C_GRY << "nickname" << C_WHT << " |" << endl;
	for (int i = 0; i < _m_nbContact; i++) {
		cout << "|-------------------------------------------|" << endl;
		cout << "|" << std::setw(10) << i + 1 << "|";
		cout << std::setw(10) << getInfos("firstName", i) << "|";
		cout << std::setw(10) << getInfos("lastName", i) << "|";
		cout << std::setw(10) << getInfos("nickname", i) << "|" << endl;
	}
	cout << "*-------------------------------------------*\n" << endl;
}

std::string Phonebook::getInfos( std::string element, int index ) {
	if (element == "firstName") {
		if (_m_contacts[index].get_firstName().size() > 10)
			return (reSize(_m_contacts[index].get_firstName()));
		return (_m_contacts[index].get_firstName());
	}
	else if (element == "lastName"){
		if (_m_contacts[index].get_lastName().size() > 10)
			return (reSize(_m_contacts[index].get_lastName()));
		return (_m_contacts[index].get_lastName());
	}
	else if (element == "nickname"){
		if (_m_contacts[index].get_nickname().size() > 10)
			return (reSize(_m_contacts[index].get_nickname()));
		return (_m_contacts[index].get_nickname());
	}
	return 0;
}

std::string Phonebook::reSize( std::string str ) {
	std::string new_str;

	new_str = str.substr(0, 9);
	new_str.insert(new_str.end(), '.');
	return (new_str);
}

void Phonebook::searchContact ( void ) {
	displayTab();
	if (_m_nbContact > 0)
		displayInfos(_m_nbContact);
}

void Phonebook::setContact( int index ) {
	cout << C_BLU << "\n----- Complete informations ------" << C_WHT << endl;
	cout << "First name : ";
	cin >> _m_contacts[index].get_firstName();
	cout << "Last name : ";
	cin >> _m_contacts[index].get_lastName();
	cout << "Nickname : ";
	cin >> _m_contacts[index].get_nickname();
	cout << "Phone Number : ";
	cin >> _m_contacts[index].get_phoneNumber();
	cout << "Darkest secret : ";
	cin >> _m_contacts[index].get_darkestSecret();
	cout << C_BLU << "--------- Contact saved! ---------\n" << C_WHT << endl;
}