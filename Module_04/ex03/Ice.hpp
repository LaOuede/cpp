/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/26 21:01:34 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ICE_HPP__
# define __ICE_HPP__

# include <iostream>
# include "AMateria.hpp"

using std::cout;
using std::endl;
using std::string;

class Ice : public AMateria {
	public:
		// Construtors & Destructors
		Ice( void ) ;                        //canonical
		Ice( Ice const & rhs );              //canonical
		~Ice( void ) ;                       //canonical

		// Overload operators
		Ice &operator=( Ice const & rhs ) ;  //canonical

		// Methods
		virtual AMateria* clone( void ) const;
		void use( ICharacter& target ) ;
};

#endif//-----------------------------------------------------------------ICE.HPP