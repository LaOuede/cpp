/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/23 19:30:31 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGANIMAL_HPP__
# define __WRONGANIMAL_HPP__

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class WrongAnimal {
	public:
		// Construtors & Destructors
		WrongAnimal( void ) ;                                  //canonical
		WrongAnimal( WrongAnimal const & rhs ) ;               //canonical
		virtual ~WrongAnimal( void ) ;                         //canonical

		// Overload operators
		WrongAnimal &operator=( WrongAnimal const & rhs ) ;    //canonical

		// Getters and Setters
		string getType( void ) const ;

		// Methods
		virtual void makeSound( void ) const ;

	protected:
		// Attributes
		string _type;
};

#endif//---------------------------------------------------------WRONGANIMAL.HPP