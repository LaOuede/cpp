/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Thunder.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/26 20:55:20 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Thunder.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
Thunder::Thunder() : AMateria() {
	AMateria::_type = "thunder";
	cout << "Thunder ⚡️ - Default constructor called" << endl;
}

Thunder::Thunder( Thunder const & rhs ) {
	*this = rhs;
	cout << "Thunder ⚡️ - Copy constructor called" << endl;
}

Thunder::~Thunder() {
	cout << "Thunder ⚡️ - Default destructor called" << endl;
}


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
Thunder &Thunder::operator=( Thunder const & rhs ) {
	if ( this != &rhs)
		this->_type = rhs.getType();
	return *this;
}


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
AMateria* Thunder::clone() const {
	return new Thunder;
}

void Thunder::use( ICharacter& target ) {
	cout << "* shoots an thunder bolt at " << target.getName() << " *" << endl;
}