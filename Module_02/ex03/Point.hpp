/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/16 08:29:12 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT_HPP__
#define __POINT_HPP__

#include "Fixed.hpp"

class Point {
	public:
		// Constructors and Destructors
		Point( void ) ;                             // canonical
		Point( float const x, float const y ) ;
		Point( Point const & rhs ) ;                // canonical
		~Point( void ) ;                            // canonical

		// Getters & Setters
		Fixed getX( void ) const ;
		Fixed getY( void ) const ;

		// Operator
		Point &operator=( Point const & rhs ) ;     // canonical

	private:
		Fixed const _x;
		Fixed const _y;
};

#endif //--------------------------------------------------------------POINT_HPP