/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/24 14:37:06 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ICHARACTER_CPP__
# define __ICHARACTER_CPP__

# include <iostream>

using std::string;

class AMateria;

class ICharacter {
	public:
		// Construtors & Destructors
		virtual ~ICharacter( void ) {}

		// Getters and Setters
		virtual string const & getName( void ) const = 0;

		// Methods
		virtual void equip( AMateria* m ) = 0;
		virtual void unequip( int idx ) = 0;
		virtual void use( int idx, ICharacter& target ) = 0;
};

#endif//----------------------------------------------------------ICHARACTER.HPP