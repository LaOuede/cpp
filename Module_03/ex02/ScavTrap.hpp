/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/27 09:18:50 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCAVTRAP_HPP__
# define __SCAVTRAP_HPP__

#include <iostream>
#include "ClapTrap.hpp"

# define SCAV_HP 100
# define SCAV_EP 50
# define SCAV_DMG 20

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class ScavTrap : virtual public ClapTrap {
	public:
		// Constructors and Destructors
		ScavTrap( void ) ;                             //canonical
		ScavTrap( string name ) ;
		ScavTrap( ScavTrap const & rhs ) ;             //canonical
		~ScavTrap( void ) ;                            //canonical

		// Overload operators
		ScavTrap &operator=( ScavTrap const & rhs ) ;  //canonical

		// Methods
		void attack( const string & target ) ;
		void beRepaired( unsigned int amount ) ;
		void displayStatus( void ) ;
		void takeDamage( unsigned int amount ) ;

		void guardGate( ) ;
		bool isGuardian( void ) ;

	protected:
		// Attributes:
		bool _guardMode ;
		static int _scav_hp ;
		static int _scav_ep ;
		static int _scav_dmg ;
};

# endif //----------------------------------------------------------SCAVTRAP.HPP