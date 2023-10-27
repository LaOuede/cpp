/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/16 08:19:27 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

#include <iostream>

using std::cerr;
using std::cout;
using std::endl;
using std::ostream;

class Fixed {
	public: 
		// Constructors and Destructors
		Fixed( void ) ;                             // canonical
		Fixed( int const i ) ;
		Fixed( float const f ) ;
		Fixed( Fixed const & rhs ) ;                // canonical
		~Fixed( void ) ;                            // canonical

		// Getters and Setters
		int getRawBits( void ) const ;
		void setRawBits( int const raw ) ;

		// Operators
		Fixed &operator=( Fixed const & rhs ) ;    // canonical

		bool operator>( Fixed const & rhs ) const ;  //comparaison
		bool operator<( Fixed const & rhs ) const ;  //comparaison
		bool operator>=( Fixed const & rhs ) const ; //comparaison
		bool operator<=( Fixed const & rhs ) const ; //comparaison
		bool operator==( Fixed const & rhs ) const ; //comparaison
		bool operator!=( Fixed const & rhs ) const ; //comparaison

		Fixed operator+( Fixed const & rhs ) const ; //arithmetic
		Fixed operator-( Fixed const & rhs ) const ; //arithmetic
		Fixed operator/( Fixed const & rhs ) const ; //arithmetic
		Fixed operator*( Fixed const & rhs ) const ; //arithmetic

		Fixed operator++( void ) ;                   //pre
		Fixed operator--( void ) ;                   //pre
		Fixed operator++( int nb ) ;                 //post
		Fixed operator--( int nb ) ;                 //post

		// Methods
		float toFloat( void ) const ;
		int toInt( void ) const ;

		static Fixed min( Fixed & nb1, Fixed & nb2) ;
		static Fixed min( Fixed const & nb1, Fixed const & nb2) ;
		static Fixed max( Fixed & nb1, Fixed & nb2) ;
		static Fixed max( Fixed const & nb1, Fixed const & nb2) ;

	private:
		// Attributes
		int _nbFixed;
		static const int _fracBits = 8;
} ;

// Overload operator
ostream & operator<<( ostream & o, Fixed const & rhs) ;

# endif //-------------------------------------------------------------FIXED_HPP