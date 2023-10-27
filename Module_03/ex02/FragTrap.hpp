/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/27 09:18:45 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAGTRAP_HPP__
# define __FRAGTRAP_HPP__

#include <iostream>
#include "ClapTrap.hpp"

# define FRAG_HP 100
# define FRAG_EP 100
# define FRAG_DMG 30

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class FragTrap : virtual public ClapTrap {
	public:
		// Constructors and Destructors
		FragTrap( void ) ;                             //canonical
		FragTrap( string name ) ;
		FragTrap( FragTrap const & rhs ) ;             //canonical
		~FragTrap( void ) ;                            //canonical

		// Overload operators
		FragTrap &operator=( FragTrap const & rhs ) ;  //canonical

		// Methods
		void attack( const string & target ) ;
		void highFivesGuys(void);
};

# endif //----------------------------------------------------------FRAGTRAP.HPP