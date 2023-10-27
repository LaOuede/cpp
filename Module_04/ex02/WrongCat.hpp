/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/23 19:31:58 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGCAT_HPP__
# define __WRONGCAT_HPP__

#include <iostream>
#include "WrongAnimal.hpp"

using std::cout;
using std::endl;
using std::string;

class WrongCat : virtual public WrongAnimal {
	public:
		// Construtors & Destructors
		WrongCat( void ) ;                                //canonical
		WrongCat( WrongCat const & rhs ) ;                //canonical
		~WrongCat( void ) ;                               //canonical

		// Overload operators
		WrongCat &operator=( WrongCat const & rhs ) ;     //canonical

		// Methods
		void makeSound( void ) const ;

};

#endif//-----------------------------------------------------------------CAT.HPP