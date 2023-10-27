/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/24 16:23:02 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
AMateria::AMateria() {
	cout << "Materia - Default constructor called" << endl;
}

AMateria::AMateria( string const & type) : _type( type ) {
	cout << "Materia - Parametric constructor called" << endl;
}

AMateria::AMateria( AMateria const & rhs ) {
	*this = rhs;
	cout << "Materia - Copy constructor called" << endl;
}

AMateria::~AMateria() {
	cout << "Materia - Default destructor called" << endl;
}


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
AMateria &AMateria::operator=( AMateria const & rhs) {
	if ( this != &rhs)
		this->_type = rhs.getType();
	return *this;
}


/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */
string const &AMateria::getType() const { return this->_type; }


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
void AMateria::use( ICharacter& target ) {
	cout << "* shoots an ice bolt at " << target.getName() << " *" << endl;
}