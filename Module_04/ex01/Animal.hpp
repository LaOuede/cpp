/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/23 19:30:37 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Animal {
	public:
		// Construtors & Destructors
		Animal( void ) ;                             //canonical
		Animal( Animal const & rhs ) ;               //canonical
		virtual ~Animal( void ) ;                    //canonical

		// Overload operators
		Animal &operator=( Animal const & rhs ) ;    //canonical

		// Getters and Setters
		string getType( void ) const ;

		// Methods
		virtual void makeSound( void ) const ;

	protected:
		// Attributes
		string _type;
};

#endif//--------------------------------------------------------------ANIMAL.HPP