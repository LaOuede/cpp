/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/26 20:58:02 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
Cure::Cure() : AMateria() {
	AMateria::_type = "cure";
	cout << "Cure 🧪 - Default constructor called" << endl;
}

Cure::Cure( Cure const & rhs ) {
	*this = rhs;
	cout << "Cure 🧪 - Copy constructor called" << endl;
}

Cure::~Cure() {
	cout << "Cure 🧪 - Default destructor called" << endl;
}


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
Cure &Cure::operator=( Cure const & rhs ) {
	if ( this != &rhs)
		this->_type = rhs.getType();
	return *this;
}


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
AMateria* Cure::clone() const {
	return new Cure;
}

void Cure::use( ICharacter& target ) {
	cout << "* heals " << target.getName() << "'s wounds *" << endl;
}