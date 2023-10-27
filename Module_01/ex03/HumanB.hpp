/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/27 08:40:13 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANB_HPP__
# define __HUMANB_HPP__

#include <iostream>
#include <string>

#include "Weapon.hpp"

using std::cout;
using std::endl;
using std::string;

class HumanB {
	public:
		// Constructor & Destructor
		HumanB( string name ) ;
		~HumanB( void ) ;

		// Getters & Setters
		void setWeapon( Weapon &weapon ) ;

		// Methods
		void attack( void ) ;

	private:
		// Attributes
		string _m_name;
		Weapon *_m_weapon;
};

#endif