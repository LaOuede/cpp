#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

# define C_WHT "\e[0m"
# define C_BOL "\e[1m"
# define C_BLU "\e[34m"
# define C_GRY "\e[90m"

class Phonebook {
	public:
		Phonebook( void );
		~Phonebook( void );
		void addContact( void );
		void displayInfos( int nbContact );
		void displayTab( void );
		void searchContact( void );

	private:
		Contact _m_contacts[8];
		int _m_nbContact;
		int _m_index;
};

#endif
