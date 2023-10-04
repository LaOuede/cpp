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
		void displayContact ( void );
		void setContact ( void );
		std::string getInfos ( std::string element );
		std::string reSize ( std::string element );

	private:
		std::string _m_firstName;
		std::string _m_lastName;
		std::string _m_nickname;
		std::string _m_phoneNumber;
		std::string _m_darkestSecret;
};

#endif