/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/23 19:30:17 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_HPP__
# define __CAT_HPP__

#include <iostream>
#include "Animal.hpp"

using std::cout;
using std::endl;
using std::string;

class Cat : virtual public Animal {
	public:
		// Construtors & Destructors
		Cat( void ) ;                             //canonical
		Cat( Cat const & rhs ) ;                  //canonical
		~Cat( void ) ;                            //canonical

		// Overload operators
		Cat &operator=( Cat const & rhs ) ;       //canonical

		// Methods
		virtual void makeSound( void ) const ;
};

#endif//-----------------------------------------------------------------CAT.HPP