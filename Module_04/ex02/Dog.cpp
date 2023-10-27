/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/27 09:35:39 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
Dog::Dog() : AAnimal() {
	AAnimal::_type = "Dog";
	this->_brain = new Brain;
	this->_brain->fillIdeas(AAnimal::_type);
	cout << "Dog 🐕 - Default constructor called" << endl;
}

Dog::Dog( Dog const & rhs ) {
	this->_type = rhs.getType();
	this->_brain = new Brain(*(rhs._brain));
	cout << "Dog 🐕 - Copy constructor called" << endl;
}

Dog::~Dog() {
	delete this->_brain;
	cout << "Dog 🐕 - Default destructor called" << endl;
}


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
Dog &Dog::operator=( Dog const & rhs ) {
	if ( this != &rhs ) {
		this->_type = rhs.getType();
		delete this->_brain;
		this->_brain = new Brain(*(rhs._brain));
	}
	return *this;
}


/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */
string const &Dog::getIdea( int i ) const { return this->_brain->getIdea(i); }
void Dog::setIdea( string idea, int i ) { this->_brain->setIdea(idea, i); }


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
void Dog::makeSound() const {
	cout << "Woof Woof" << endl;
}