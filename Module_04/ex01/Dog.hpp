/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/23 19:30:50 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_HPP__
# define __DOG_HPP__

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

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

		// Getters & Setters
		string const &getIdea( int i ) const ;
		void setIdea( string idea, int i ) ;

		// Methods
		virtual void makeSound( void ) const ;

	private:
		Brain* _brain;
};

#endif//-----------------------------------------------------------------DOG.HPP