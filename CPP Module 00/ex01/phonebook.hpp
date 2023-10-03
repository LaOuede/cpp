#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

# define C_WHT "\e[0m"
# define C_BOL "\e[1m"
# define C_ITA "\e[3m"
# define C_UND "\e[4m"
# define C_RED "\e[31m"
# define C_GRN "\e[32m"
# define C_YEL "\e[33m"
# define C_BLU "\e[34m"
# define C_MAG "\e[35m"
# define C_CYA "\e[36m"
# define C_GRY "\e[90m"

class Phonebook {
	public:
		Phonebook( void );
		~Phonebook( void );
		void addContact( int index ) ;
		void searchContact( int index );

	private:
		Contact _m_contacts[8];
};

#endif