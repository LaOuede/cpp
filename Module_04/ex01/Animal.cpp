/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/23 19:41:55 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
Animal::Animal() : _type("Indistinct animal") {
	cout << "Animal 🦖 - Default constructor called" << endl;
}

Animal::Animal( Animal const & rhs ) {
	cout << "Animal 🦖 - Copy constructor called" << endl;
	*this = rhs;
}

Animal::~Animal() {
	cout << "Animal 🦖 - Default destructor called" << endl;
}


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
Animal &Animal::operator=( Animal const & rhs ) {
	if ( this != &rhs )
		this->_type = rhs.getType();
	return *this;
}


/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */
string Animal::getType() const { return this->_type; }


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
void Animal::makeSound() const {
	cout << "*** Indistinct animal noise ***" << endl;
}