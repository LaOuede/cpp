/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/23 19:31:38 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AANIMAL_HPP__
# define __AANIMAL_HPP__

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class AAnimal {
	public:
		// Construtors & Destructors
		AAnimal( void ) ;                             //canonical
		AAnimal( AAnimal const & rhs ) ;              //canonical
		virtual ~AAnimal( void ) ;                    //canonical

		// Overload operators
		AAnimal &operator=( AAnimal const & rhs ) ;   //canonical

		// Getters and Setters
		string getType( void ) const ;

		// Methods
		virtual void makeSound( void ) const = 0;

	protected:
		// Attributes
		string _type;
};

#endif//-------------------------------------------------------------AANIMAL.HPP