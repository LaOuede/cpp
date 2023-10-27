/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/23 19:40:54 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
AAnimal::AAnimal() : _type("Indistinct animal") {
	cout << "Animal 🦖 - Default constructor called" << endl;
}

AAnimal::AAnimal( AAnimal const & rhs ) {
	cout << "Animal 🦖 - Copy constructor called" << endl;
	*this = rhs;
}

AAnimal::~AAnimal() {
	cout << "Animal 🦖 - Default destructor called" << endl;
}


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
AAnimal &AAnimal::operator=( AAnimal const & rhs ) {
	if ( this != &rhs )
		this->_type = rhs.getType();
	return *this;
}


/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */
string AAnimal::getType() const { return this->_type; }


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
void AAnimal::makeSound() const {
	cout << "*** Indistinct animal noise ***" << endl;
}