/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/27 09:19:02 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DIAMONDTRAP_HPP__
# define __DIAMONDTRAP_HPP__

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class DiamondTrap : public ScavTrap, public FragTrap {
	public:
		// Constructors and Destructors
		DiamondTrap( void ) ;                                //canonical
		DiamondTrap( string name ) ;
		DiamondTrap( DiamondTrap const & rhs ) ;             //canonical
		~DiamondTrap( void ) ;                               //canonical

		// Overload operators
		DiamondTrap &operator=( DiamondTrap const & rhs ) ;  //canonical

		// Methods:
		void whoAmI( void );
		using ScavTrap::attack ;
		using FragTrap::_frag_hp ;
		using ScavTrap::_scav_ep ;
		using FragTrap::_frag_dmg ;

	private:
		// Attributes:
		string _name;
		
};

# endif //-------------------------------------------------------DIAMONDTRAP.HPP