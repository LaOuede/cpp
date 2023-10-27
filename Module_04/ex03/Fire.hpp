/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/26 21:01:16 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIRE_HPP__
# define __FIRE_HPP__

# include <iostream>
# include "AMateria.hpp"

using std::cout;
using std::endl;
using std::string;

class Fire : public AMateria {
	public:
		// Construtors & Destructors
		Fire( void ) ;                         //canonical
		Fire( Fire const & rhs );              //canonical
		~Fire( void ) ;                        //canonical

		// Overload operators
		Fire &operator=( Fire const & rhs ) ;  //canonical

		// Methods
		virtual AMateria* clone( void ) const;
		void use( ICharacter& target ) ;
};

#endif//----------------------------------------------------------------FIRE.HPP