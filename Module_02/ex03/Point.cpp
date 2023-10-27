/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/27 09:16:19 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
Point::Point() : _x(0), _y(0) {}

Point::Point( float const x, float const y) : _x(x), _y(y) {}

Point::Point( Point const & rhs ) : _x(0), _y(0) {
	*this = rhs;
}

Point::~Point() {}


/* ************************************************************************** */
/* Getters & Setters                                                          */
/* ************************************************************************** */
Fixed Point::getX( void ) const {
	return this->_x;
}

Fixed Point::getY( void ) const {
	return this->_y;
}


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
/* 
const_cast:
	Performs the type casting and is used to modify the const-ness of the variable.
<Fixed&>:
	It's the cast's target type and specifies that you want to cast
	from a const reference to a non-const reference of the Fixed class.
Warning:
	Use const_cast with caution because casting away const-ness can lead to
	undefined behavior
 */
Point &Point::operator=( Point const &rhs ) {
	const_cast<Fixed&>(_x) = rhs.getX();
	const_cast<Fixed&>(_y) = rhs.getY();
	return *this;
}