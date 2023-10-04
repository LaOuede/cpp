#ifndef CONTACT_H
# define CONTACT_H

# define C_WHT "\e[0m"
# define C_BOL "\e[1m"
# define C_RED "\e[31m"
# define C_BLU "\e[34m"
# define C_GRY "\e[90m"

class Contact {
	public:
		Contact( void );
		~Contact( void );
		std::string &get_firstName( void );
		std::string &get_lastName( void );
		std::string &get_nickname( void );
		std::string &get_phoneNumber( void );
		std::string &get_darkestSecret( void );

	private:
		std::string _m_firstName;
		std::string _m_lastName;
		std::string _m_nickname;
		std::string _m_phoneNumber;
		std::string _m_darkestSecret;
};

#endif