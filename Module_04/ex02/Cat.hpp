/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/23 19:31:45 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_HPP__
# define __CAT_HPP__

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

using std::cout;
using std::endl;
using std::string;

class Cat : virtual public AAnimal {
	public:
		// Construtors & Destructors
		Cat( void ) ;                             //canonical
		Cat( Cat const & rhs ) ;                  //canonical
		~Cat( void ) ;                            //canonical

		// Overload operators
		Cat &operator=( Cat const & rhs ) ;       //canonical

		// Getters & Setters
		string const &getIdea( int i ) const ;
		void setIdea( string idea, int i ) ;

		// Methods
		virtual void makeSound( void ) const ;

	private:
		Brain* _brain;
};

#endif//-----------------------------------------------------------------CAT.HPP