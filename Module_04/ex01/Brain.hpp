/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/26 20:50:33 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__

#include <array>
#include <iostream>
#include <fstream>

#define NB_IDEAS 100

using std::cout;
using std::endl;
using std::array;
using std::string;

class Brain {
	public:
		// Construtors & Destructors
		Brain( void ) ;                             //canonical
		Brain( Brain const & rhs ) ;                //canonical
		~Brain( void ) ;                            //canonical

		// Getters & Setters
		string const &getIdea( int i ) const ;
		Brain* copyBrain( void ) ;
		void setIdea( string idea, int i ) ;


		// Overload operators
		Brain &operator=( Brain const & rhs ) ;     //canonical
		
		// Methods
		void fillIdeas( string type ) ;

	private:
		// Attributes
		array<string, NB_IDEAS> _ideas;
};

#endif//---------------------------------------------------------------BRAIN.HPP