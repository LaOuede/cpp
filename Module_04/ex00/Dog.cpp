/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/23 19:05:59 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
Dog::Dog() : Animal() {
	Animal::_type = "Dog";
	cout << "Dog 🐕 - Default constructor called" << endl;
}

Dog::Dog( Dog const & rhs ) {
	*this = rhs;
	cout << "Dog 🐕 - Copy constructor called" << endl;
}

Dog::~Dog() {
	cout << "Dog 🐕 - Default destructor called" << endl;
}


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
Dog &Dog::operator=( Dog const & rhs ) {
	if ( this != &rhs )
		this->_type = rhs.getType();
	return *this;
}


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
void Dog::makeSound() const {
	cout << "Woof Woof" << endl;
}