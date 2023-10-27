/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/27 08:40:35 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_HPP__
# define __WEAPON_HPP__

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Weapon {
	public:
		// Constructor & Destructor
		Weapon( string name ) ;
		~Weapon( void ) ;

		// Getters & Setters
		const string &getType( void ) const ;
		void setType ( const string &name ) ;

	private:
		// Attributes
		string _m_name;
};

#endif