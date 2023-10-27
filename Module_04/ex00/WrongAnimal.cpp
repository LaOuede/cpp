/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/23 19:41:42 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
WrongAnimal::WrongAnimal() : _type("Indistinct Wrong animal") {
	cout << "Wrong Animal ❌ - Default constructor called" << endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const & rhs ) {
	cout << "Wrong Animal ❌ - Copy constructor called" << endl;
	*this = rhs;
}

WrongAnimal::~WrongAnimal() {
	cout << "Wrong animal ❌ - Default destructor called" << endl;
}


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
WrongAnimal &WrongAnimal::operator=( WrongAnimal const & rhs ) {
	if ( this != &rhs )
		this->_type = rhs.getType();
	return *this;
}


/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */
string WrongAnimal::getType() const { return this->_type; }


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
void WrongAnimal::makeSound() const {
	cout << "*** Indistinct Wrong animal noise ***" << endl;
}