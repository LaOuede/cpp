/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/27 09:15:17 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
Fixed::Fixed() : _nbFixed(0) {
	cout << "Default constructor called" << endl;
	return;
}

Fixed::Fixed( int const i) {
	cout << "Int constructor called" << endl;
	this->setRawBits(i << this->_fracBits);
	return;
}

Fixed::Fixed( float const f) {
	cout << "Float constructor called" << endl;
	this->setRawBits(roundf(f * (1 << this->_fracBits)));
	return;
}


Fixed::Fixed( Fixed const & rhs) {
	cout << "Copy constructor called" << endl;
	*this = rhs;
	return;
}

Fixed::~Fixed( void ) {
	cout << "Destructor called " << endl;
	return;
}


/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */
int Fixed::getRawBits() const { return this->_nbFixed; }
void Fixed::setRawBits( int const raw) { this->_nbFixed = raw; }


/* ************************************************************************** */
/* Operators                                                                  */
/* ************************************************************************** */
Fixed & Fixed::operator=( Fixed const & rhs) {
	cout << "Copy assignment operator called" << endl;
	if ( this != &rhs )
		this->_nbFixed = rhs.getRawBits();
	return *this;
}

ostream & operator<<( ostream & o, Fixed const & rhs) {
	o << rhs.toFloat();
	return o;
}

/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */

/* 
	Right-shifting an integer effectively discards the lower bits, 
	effectively removing the fractional part. The result of the shift 
	is the integer part of the fixed-point number.
 */
int Fixed::toInt() const {
	return this->_nbFixed >> this->_fracBits ;
}

/* 
(float)this->_nbFixed :
	It is mandatory to cast a float here to ensure that the division result 
	is a floating-point number. Without the cast, it would be an integer division,
	which truncates the decimal part.

/ (1 << this->_fracBits) :
	This is the division operation.
	It divides the value stored in _nbFixed by the scaling factor.
	The scaling factor is calculated as 1 left-shifted by _fracBits positions.
	The division effectively scales down the fixed-point value by dividing it by
	2 raised to the power of _fracBits.
 */
float Fixed::toFloat() const {
	return (float)this->_nbFixed / (1 << this->_fracBits);
}