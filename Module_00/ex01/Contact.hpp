/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/27 08:37:22 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# define C_WHT "\e[0m"
# define C_BOL "\e[1m"
# define C_RED "\e[31m"
# define C_BLU "\e[34m"
# define C_GRY "\e[90m"

#include <iostream> // std::cout, std::cin, std::endl
#include <iomanip> // std::setw
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Contact {
	public:
		// Constructor & Destructor
		Contact( void );
		~Contact( void );

		// Getters & setters
		const string &get_firstName( void ) const ;
		const string &get_lastName( void ) const ;
		const string &get_nickname( void ) const ;
		const string &get_phoneNumber( void ) const ;
		const string &get_darkestSecret( void ) const ;
		void set_firstName (const string &firstName) ;
		void set_lastName (const string &lastName) ;
		void set_nickname (const string &nickname) ;
		void set_phoneNumber (const string &phoneNumber) ;
		void set_darkestSecret (const string &darkestSecret) ;

	private:
		// Attributes
		string _m_firstName;
		string _m_lastName;
		string _m_nickname;
		string _m_phoneNumber;
		string _m_darkestSecret;
};

#endif