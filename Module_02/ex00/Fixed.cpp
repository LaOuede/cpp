/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/27 09:15:07 by gwenolalero      ###   ########.fr       */
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
int Fixed::getRawBits() const {
	cout << "getRawBits member function called" << endl;
	return this->_nbFixed;
}

void Fixed::setRawBits( int const raw) {
	this->_nbFixed = raw;
}


/* ************************************************************************** */
/* Operator                                                                   */
/* ************************************************************************** */
Fixed & Fixed::operator=( Fixed const & rhs) {
	cout << "Copy assignment operator called" << endl;
	if ( this != &rhs )
		this->_nbFixed = rhs.getRawBits();
	return *this;
}