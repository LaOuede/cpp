#ifndef PHONEBOOK_H
# define PHONEBOOK_H

class Phonebook {
	public:
		Phonebook( void );
		~Phonebook( void );

	private:
		std::string const _m_contacts[8];
};

#endif