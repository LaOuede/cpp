/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/27 09:15:57 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
Fixed::Fixed() : _nbFixed(0) {}

Fixed::Fixed( int const i) {
	this->setRawBits(i << this->_fracBits);
}

Fixed::Fixed( float const f) {
	this->setRawBits(roundf(f * (1 << this->_fracBits)));
}

Fixed::Fixed( Fixed const & rhs) {
	*this = rhs;
}

Fixed::~Fixed() {}


/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */
int Fixed::getRawBits() const { return this->_nbFixed; }
void Fixed::setRawBits( int const raw) { this->_nbFixed = raw; }


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
Fixed &Fixed::operator=( Fixed const & rhs ) {
	if ( this != &rhs )
		this->_nbFixed = rhs.getRawBits();
	return *this;
}

ostream &operator<<( ostream & o, Fixed const & rhs ) {
	o << rhs.toFloat();
	return o;
}

// Comparison Operators
/* condition ? expression_if_true : expression_if_false; */
bool Fixed::operator>( Fixed const & rhs) const {
	return this->_nbFixed > rhs.getRawBits() ? true : false ;
}

bool Fixed::operator<( Fixed const & rhs ) const {
	return this->_nbFixed < rhs.getRawBits() ? true : false ;
}

bool Fixed::operator>=( Fixed const & rhs ) const {
	return this->_nbFixed >= rhs.getRawBits() ? true : false ;
}

bool Fixed::operator<=( Fixed const & rhs ) const {
	return this->_nbFixed <= rhs.getRawBits() ? true : false ;
}

bool Fixed::operator==( Fixed const & rhs ) const {
	return this->_nbFixed == rhs.getRawBits() ? true : false ;
}

bool Fixed::operator!=( Fixed const & rhs ) const {
	return this->_nbFixed != rhs.getRawBits() ? true : false ;
}

// Arithmetic Operators
Fixed Fixed::operator+( Fixed const & rhs ) const {
	return this->toFloat() + rhs.toFloat();
}

Fixed Fixed::operator-( Fixed const & rhs ) const {
	return this->toFloat() - rhs.toFloat();
}

Fixed Fixed::operator/( Fixed const & rhs ) const {
	return this->toFloat() / rhs.toFloat();
}

Fixed Fixed::operator*( Fixed const & rhs ) const {
	return this->toFloat() * rhs.toFloat();
}

// Incrementation and Decrementation Operators
Fixed Fixed::operator++() {
	++this->_nbFixed;
	return *this;
}

Fixed Fixed::operator--() {
	--this->_nbFixed;
	return *this;
}

Fixed Fixed::operator++( int nb ) {
	if (!nb)
		nb = 1;
	Fixed temp = *this;
	this->_nbFixed += nb;
	return temp;
}

Fixed Fixed::operator--( int nb ) {
	if (!nb)
		nb = 1;
	Fixed temp = *this;
	this->_nbFixed -= nb;
	return temp;
}


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
int Fixed::toInt() const {
	return this->_nbFixed >> this->_fracBits ;
}

float Fixed::toFloat() const {
	return (float)this->_nbFixed / (1 << this->_fracBits);
}

// Comparison Functions
/* condition ? expression_if_true : expression_if_false; */
Fixed Fixed::min( Fixed & nb1, Fixed & nb2) {
	return nb1.toFloat() < nb2.toFloat() ? nb1.toFloat() : nb2.toFloat() ;
}

Fixed Fixed::min( Fixed const & nb1, Fixed const & nb2) {
	return nb1.toFloat() < nb2.toFloat() ? nb1.toFloat() : nb2.toFloat() ;
}

Fixed Fixed::max( Fixed & nb1, Fixed & nb2) {
	return nb1.toFloat() > nb2.toFloat() ? nb1.toFloat() : nb2.toFloat() ;

}

Fixed Fixed::max( Fixed const & nb1, Fixed const & nb2) {
	return nb1.toFloat() > nb2.toFloat() ? nb1.toFloat() : nb2.toFloat() ;
}