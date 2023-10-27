/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/26 20:55:59 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
Ice::Ice() : AMateria() {
	AMateria::_type = "ice";
	cout << "Ice 🧊 - Default constructor called" << endl;
}

Ice::Ice( Ice const & rhs ) {
	*this = rhs;
	cout << "Ice 🧊 - Copy constructor called" << endl;
}

Ice::~Ice() {
	cout << "Ice 🧊 - Default destructor called" << endl;
}


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
Ice &Ice::operator=( Ice const & rhs ) {
	if ( this != &rhs)
		this->_type = rhs.getType();
	return *this;
}


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
AMateria *Ice::clone() const {
	return new Ice;
}

void Ice::use( ICharacter& target ) {
	cout << "* shoots an ice bolt at " << target.getName() << " *" << endl;
}