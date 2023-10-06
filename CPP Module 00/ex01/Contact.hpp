/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/06 11:12:12 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# define C_WHT "\e[0m"
# define C_BOL "\e[1m"
# define C_RED "\e[31m"
# define C_BLU "\e[34m"
# define C_GRY "\e[90m"

class Contact {
	public:
		// Constructor & Destructor
		Contact( void );
		~Contact( void );
		// Getters & setters
		const std::string &get_firstName( void ) const ;
		const std::string &get_lastName( void ) const ;
		const std::string &get_nickname( void ) const ;
		const std::string &get_phoneNumber( void ) const ;
		const std::string &get_darkestSecret( void ) const ;
		void set_firstName (const std::string &firstName) ;
		void set_lastName (const std::string &lastName) ;
		void set_nickname (const std::string &nickname) ;
		void set_phoneNumber (const std::string &phoneNumber) ;
		void set_darkestSecret (const std::string &darkestSecret) ;

	private:
		// Attributes
		std::string _m_firstName;
		std::string _m_lastName;
		std::string _m_nickname;
		std::string _m_phoneNumber;
		std::string _m_darkestSecret;
};

#endif