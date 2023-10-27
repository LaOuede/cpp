/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/26 09:55:48 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CHARACTER_HPP__
# define __CHARACTER_HPP__

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

# define INVENTORY_SIZE 4
# define COLLECTOR_SIZE 500

using std::cout;
using std::endl;
using std::string;

class Character : public ICharacter {
	public:
		// Construtors & Destructors
		Character( void ) ;                              //canonical
		Character( string const name ) ;
		Character( Character const & rhs );              //canonical
		~Character( void ) ;                             //canonical

		// Overload operators
		Character &operator=( Character const & rhs ) ;  //canonical

		// Getters and Setters
		virtual string const & getName( void ) const ;
		string const getItem( uint idx ) const ;

		// Methods
		void displayInfos( void ) ;
		virtual void equip( AMateria* m );
		void itemTracker( uint idx ) ;
		virtual void unequip( int idx );
		virtual void use( int idx, ICharacter& target );

	private:
		// Attributes
		string _name;
		AMateria* _items[INVENTORY_SIZE];
		uint _nbItems;
		AMateria* _droppedIt[COLLECTOR_SIZE];
		uint _nbDroppedIt;
};

#endif//-----------------------------------------------------------CHARACTER.HPP