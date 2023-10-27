/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/23 19:05:36 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
Cat::Cat() : Animal() {
	Animal::_type = "Cat";
	cout << "Cat 🐈 - Default constructor called" << endl;
}

Cat::Cat( Cat const & rhs ) {
	*this = rhs;
	cout << "Cat 🐈 - Copy constructor called" << endl;
}

Cat::~Cat() {
	cout << "Cat 🐈 - Default destructor called" << endl;
}


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
Cat &Cat::operator=( Cat const & rhs ) {
	if ( this != &rhs )
		this->_type = rhs.getType();
	return *this;
}


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
void Cat::makeSound() const {
	cout << "Meeeeoooow" << endl;
}