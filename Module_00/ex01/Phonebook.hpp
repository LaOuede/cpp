/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/27 08:37:55 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# define C_WHT "\e[0m"
# define C_BOL "\e[1m"
# define C_RED "\e[31m"
# define C_BLU "\e[34m"
# define C_GRY "\e[90m"

#include <iostream> // std::cout, std::cin, std::endl
#include <iomanip> // std::setw
#include <string>
#include "Contact.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Phonebook {
	public:
		// Constructor & Destructor
		Phonebook( void );
		~Phonebook( void );

		// Methods
		void addContact( void );
		void displayContact( int index );
		void displayInfos( int nbContact );
		void displayTab( void );
		void fillTab( void );
		string getInfos( string element, int index );
		string reSize( string element );
		void searchContact( void );
		void setContact( int index );

	private:
		// Attributes
		Contact _m_contacts[8];
		int _m_nbContact;
		int _m_index;
};

#endif