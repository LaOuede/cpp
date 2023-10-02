#ifndef CONTACT_H
# define CONTACT_H

class Contact {
	public:
		Contact( void );
		~Contact( void );

	private:
		std::string _m_firstname;
		std::string _m_lastname;
		std::string _m_nickname;
		std::string _m_phoneNumber;
		std::string _m_darkestSecret;
};

#endif