/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/19 11:07:12 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
WrongCat::WrongCat() : WrongAnimal() {
	WrongAnimal::_type = "WrongCat";
	cout << "WrongCat 🦄 - Default constructor called" << endl;
}

WrongCat::WrongCat( WrongCat const & rhs ) {
	cout << "WrongCat 🦄 - Copy constructor called" << endl;
	*this = rhs;
}

WrongCat::~WrongCat() {
	cout << "WrongCat 🦄 - Default destructor called" << endl;
}


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
WrongCat &WrongCat::operator=( WrongCat const & rhs ) {
	if ( this != &rhs )
		this->_type = rhs.getType();
	return *this;
}


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
void WrongCat::makeSound() const {
	cout << "Uniiicoooorn" << endl;
}