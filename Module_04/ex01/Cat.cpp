/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/27 09:34:59 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
Cat::Cat() : Animal() {
	Animal::_type = "Cat";
	this->_brain = new Brain;
	this->_brain->fillIdeas(Animal::_type);
	cout << "Cat 🐈 - Default constructor called" << endl;
}

Cat::Cat( Cat const & rhs ) {
	this->_type = rhs.getType();
	this->_brain = new Brain(*(rhs._brain));
	cout << "Cat 🐈 - Copy constructor called" << endl;
}

Cat::~Cat() {
	delete this->_brain;
	cout << "Cat 🐈 - Default destructor called" << endl;
}


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
Cat &Cat::operator=( Cat const & rhs ) {
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
string const &Cat::getIdea( int i ) const { return this->_brain->getIdea(i); }
void Cat::setIdea( string idea, int i ) { this->_brain->setIdea(idea, i); }


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
void Cat::makeSound() const {
	cout << "Meeeeoooow" << endl;
}