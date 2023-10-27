/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dagger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/26 20:57:42 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dagger.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
Dagger::Dagger() : AMateria() {
	AMateria::_type = "dagger";
	cout << "Dagger 🗡️ - Default constructor called" << endl;
}

Dagger::Dagger( Dagger const & rhs ) {
	*this = rhs;
	cout << "Dagger 🗡️ - Copy constructor called" << endl;
}

Dagger::~Dagger() {
	cout << "Dagger 🗡️ - Default destructor called" << endl;
}


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
Dagger &Dagger::operator=( Dagger const & rhs ) {
	if ( this != &rhs)
		this->_type = rhs.getType();
	return *this;
}


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
AMateria* Dagger::clone() const {
	return new Dagger;
}

void Dagger::use( ICharacter& target ) {
	cout << "* throws a dagger at " << target.getName() << " *" << endl;
}