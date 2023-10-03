#include <iostream> // std::cout, std::endl
#include <iomanip> // std::setw
#include <string>
#include "Phonebook.hpp"

using std::cin;
using std::cout;
using std::endl;

void Phonebook::displayInfos( int nbContact ) {
	int	contactToDisplay;

	do {
		cout << "Contact to display : ";
		cin >> contactToDisplay;
		if (! cin.fail() && contactToDisplay > 0 && contactToDisplay <= nbContact) {
			_m_contacts[contactToDisplay - 1].displayContact();
			return ;
		}
		else {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
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
		cout << std::setw(10) << _m_contacts[i].getInfos("firstName") << "|";
		cout << std::setw(10) << _m_contacts[i].getInfos("lastName") << "|";
		cout << std::setw(10) << _m_contacts[i].getInfos("nickname") << "|" << endl;
	}
	cout << "*-------------------------------------------*\n" << endl;
}

void Phonebook::searchContact ( void ) {
	displayTab();
	if (_m_nbContact > 0)
		displayInfos(_m_nbContact);
}

void Phonebook::addContact ( void ) {
	if (_m_nbContact <= 7)
		_m_nbContact++;
	_m_contacts[_m_index].setContact();
	_m_index++;
	if (_m_index == 8)
		_m_index = 0;
}

Phonebook::Phonebook( void ) : _m_nbContact(0), _m_index(0) {
	std::cout << C_GRY << "Phonebook has been created" << C_WHT << std::endl;
	return;
}

Phonebook::~Phonebook( void ) {
	std::cout << C_GRY << "Phonebook has been destroyed" << C_WHT << std::endl;
	return;
}
