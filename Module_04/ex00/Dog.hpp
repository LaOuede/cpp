/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/23 19:06:05 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_HPP__
# define __DOG_HPP__

#include <iostream>
#include "Animal.hpp"

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class Dog : virtual public Animal {
	public:
		// Construtors & Destructors
		Dog( void ) ;                             //canonical
		Dog( Dog const & rhs ) ;                  //canonical
		~Dog( void ) ;                            //canonical

		// Overload operators
		Dog &operator=( Dog const & rhs ) ;       //canonical

		// Methods
		virtual void makeSound( void ) const ;
};

#endif//-----------------------------------------------------------------DOG.HPP