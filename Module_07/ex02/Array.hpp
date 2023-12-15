/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/03 08:56:54 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY_HPP__
# define __ARRAY_HPP__

# include <iostream>

# define C_BOL "\e[1m"
# define C_ITA "\e[3m"
# define C_RED "\e[31m"
# define C_WHT "\e[0m"

using std::cout;
using std::endl;
using std::exception;
using std::ostream;

template <typename T>
class Array {
	public:
		// Const. & Dest.
		Array( void ) ;                         //canonical
		Array( unsigned int n ) ;
		Array( Array const &rhs ) ;             //canonical
		~Array( void ) ;                        //canonical

		// Operators overload
		Array &operator=( Array const &rhs ) ;  //canonical
		T &operator[]( unsigned int index ) ;

		// Functions
		unsigned int size( void ) const ;

		// Exceptions
		class BadIndex : public exception {
			public:
				virtual const char *what() const throw();
		};

	private:
		// Attributes
		T *_array;
		unsigned int _size;
};

# include "Array.tpp"

#endif //------------------------------------------------------------- ARRAY.HPP