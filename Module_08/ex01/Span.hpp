/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/12/04 08:15:49 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAN_HPP__
# define __SPAN_HPP__

# include <algorithm>
# include <iostream>
# include <vector>

# define C_BOL "\e[1m"
# define C_BLU "\e[34m"
# define C_ITA "\e[3m"
# define C_RED "\e[31m"
# define C_WHT "\e[0m"

using std::cout;
using std::endl;
using std::exception;
using std::ostream;
using std::sort;
using std::vector;

class Span {
	public:
		// Const. & Dest.
		Span( void ) ;                        //canonical
		Span( uint N ) ;
		Span( Span const &rhs ) ;             //canonical
		~Span( void ) ;                       //canonical

		// Operators overload
		Span &operator=( Span const &rhs ) ;  //canonical

		// Getters & Setters
		int getMaxSize( void ) const ;
		int getSize( void ) const ;
		vector<int> getVector( void ) const ;

		// Functions
		void addNumber( int const toAdd ) ;
		void addNumber( void ) ;
		int longestSpan( void ) const ;
		int shortestSpan( void ) const ;

		// Exceptions
		class NegativeValue : public exception {
			public:
				virtual const char *what() const throw() ;
		};

		class OverMaxSize : public exception {
			public:
				virtual const char *what() const throw() ;
		};

		class SizeTooSmall : public exception {
			public:
				virtual const char *what() const throw() ;
		};

	private:
		// Attributes
		uint const _maxSize;
		vector<int> _v;
};

// (<<) overload operator
ostream &operator<<( ostream &o, Span const &rhs );

#endif //-------------------------------------------------------------- SPAN.HPP