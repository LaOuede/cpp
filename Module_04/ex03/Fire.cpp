/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/26 20:57:18 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fire.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
Fire::Fire() : AMateria() {
	AMateria::_type = "fire";
	cout << "Fire 🔥 - Default constructor called" << endl;
}

Fire::Fire( Fire const & rhs ) {
	*this = rhs;
	cout << "Fire 🔥 - Copy constructor called" << endl;
}

Fire::~Fire() {
	cout << "Fire 🔥 - Default destructor called" << endl;
}


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
Fire &Fire::operator=( Fire const & rhs ) {
	if ( this != &rhs)
		this->_type = rhs.getType();
	return *this;
}


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
AMateria* Fire::clone() const {
	return new Fire;
}

void Fire::use( ICharacter& target ) {
	cout << "* shoots an fire bolt at " << target.getName() << " *" << endl;
}