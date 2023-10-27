/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/27 09:17:36 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_HPP__
# define __CLAPTRAP_HPP__

#include <iostream>

# define CLAP_HP 10
# define CLAP_EP 10
# define CLAP_DMG 0

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class ClapTrap {
	public:
		// Constructors and Destructors
		ClapTrap( void ) ;                             //canonical
		ClapTrap( string name ) ;
		ClapTrap( ClapTrap const & rhs ) ;             //canonical
		~ClapTrap( void ) ;                            //canonical

		// Getters and Setters
		string const &getName( void ) const ;
		int const &getHP( void ) const ;
		int const &getEnergy( void ) const ;
		int const &getAtkDamage( void ) const ;
		void setHP( int const &hp ) ;

		// Overload operators
		ClapTrap &operator=( ClapTrap const & rhs ) ;  //canonical

		// Methods
		void attack( const string & target ) ;
		void beRepaired( uint amount ) ;
		void displayStatus( void ) ;
		bool hasEnergy( void ) ;
		bool isAlive( void ) ;
		void takeDamage( uint amount ) ;

	private:
		// Attributes
		string _name; 
		int _hp ;
		int _energy;
		int _atkDamage;
};

# endif //----------------------------------------------------------CLAPTRAP.HPP