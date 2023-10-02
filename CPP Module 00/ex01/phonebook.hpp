#ifndef PHONEBOOK_H
# define PHONEBOOK_H

class Phonebook {
	private:
		std::string const contacts[8][5];

	public:
		Phonebook( std::string const contacts );
		~Phonebook( void );
};

class Contact {
	private:
		std::string _firstname;
		std::string _lastname;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;

	public:
		Contact( void );
		~Contact( void );
};

#endif