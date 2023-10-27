/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/26 21:00:47 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CURE_HPP__
# define __CURE_HPP__

# include <iostream>
# include "AMateria.hpp"

using std::cout;
using std::endl;
using std::string;

class Cure : public AMateria {
	public:
		// Construtors & Destructors
		Cure( void ) ;                         //canonical
		Cure( Cure const & rhs );              //canonical
		~Cure( void ) ;                        //canonical

		// Overload operators
		Cure &operator=( Cure const & rhs ) ;  //canonical

		// Methods
		virtual AMateria* clone( void ) const;
		void use( ICharacter& target ) ;
};

#endif//-----------------------------------------------------------------ICE.HPP