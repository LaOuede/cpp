/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/06 11:12:52 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

# define C_WHT "\e[0m"
# define C_BOL "\e[1m"
# define C_RED "\e[31m"
# define C_BLU "\e[34m"
# define C_GRY "\e[90m"

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
		std::string getInfos( std::string element, int index );
		std::string reSize( std::string element );
		void searchContact( void );
		void setContact( int index );

	private:
		// Attributes
		Contact _m_contacts[8];
		int _m_nbContact;
		int _m_index;
};

#endif