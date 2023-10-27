/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/11 17:28:21 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL_HPP__
# define __HARL_HPP__

#include <iostream>
#include <string>
#include <sstream>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class Harl {
	public:
		// Constructor & destructor
		Harl( void ) ;
		~Harl( void ) ;
		// Methods
		void complain( string level ) ;

	private:
		// Attributes
		string _tabLevel[4];

		typedef void (Harl::*fptr)( void ) const ;
		fptr _ptrDebug;
		fptr _ptrInfo;
		fptr _ptrWarning;
		fptr _ptrError;

		enum _Level {
			DEBUG,
			INFO,
			WARNING,
			ERROR,
		};

		// Methods
		void _debug( void ) const ;
		void _info( void ) const ;
		void _warning( void ) const ;
		void _error( void ) const ;
};

#endif