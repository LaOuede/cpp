/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/16 08:10:55 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

class Fixed {
	public: 
		// Constructors and Destructors
		Fixed( void ) ;                             // canonical
		Fixed( Fixed const & rhs ) ;                // canonical
		~Fixed( void ) ;                            // canonical

		// Getters and Setters
		int getRawBits( void ) const ;
		void setRawBits( int const raw ) ;

		// Operators
		Fixed & operator=( Fixed const & rhs ) ;    // canonical

	private:
		// Attributes
		int _nbFixed;
		static const int _fracBits = 8;
} ;

# endif //-------------------------------------------------------------FIXED_HPP