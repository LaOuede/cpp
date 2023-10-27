/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/06 17:48:55 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"

#ifndef EVAL
# define EVAL 0
#endif

void displayStart( void ) {
	cout << endl;
	cout << C_BOL << "------- 🟢 Welcome to 📞 Phonebook 📞 --------\n" << C_WHT << endl;
	cout << "**********************************************" << endl;
	cout << "* Type "<< C_BLU << "ADD " << C_WHT << "to add a new contact to Phonebook *" << endl;
	cout << "* Type "<< C_BLU << "SEARCH " << C_WHT << "to display contacts            *" << endl;
	cout << "* Type "<< C_BLU << "EXIT " << C_WHT << "to quit the programts            *" << endl;
	cout << "**********************************************\n" << endl;
}

int main( void ) {
	Phonebook phonebook;
	std::string cmd;

	displayStart();
	if (EVAL)
		phonebook.fillTab();
	do {
		cout << "🔵 Phonebøøk$ ";
		cin >> cmd;
		if (cmd ==  "SEARCH")
			phonebook.searchContact();
		else if (cmd == "ADD")
			phonebook.addContact();
		else if (cmd != "EXIT")
			cout << C_RED << "Phonebook : usage : command not found " << C_WHT << endl;
	} while (!cin.fail() && cmd != "EXIT");
	cout << C_BOL << "\n----------- 🔴 quitting program... -----------\n" << C_WHT << endl;
	return 0;
}