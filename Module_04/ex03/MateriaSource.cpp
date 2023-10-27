/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/25 18:02:00 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
MateriaSource::MateriaSource() : IMateriaSource(), _nbMateria( 0 ) {
	cout << "MateriaSource 🧙‍♂️ - Default constructor called" << endl;
	for ( uint i = 0; i < MATERIA_SIZE; i++) {
		this->_materia[i] = nullptr;
	}
}

MateriaSource::MateriaSource( MateriaSource const & rhs ) {
	cout << "MateriaSource 🧙‍♂️ - Copy constructor called" << endl;
	this->_nbMateria = rhs._nbMateria;
	for ( uint i = 0; i < MATERIA_SIZE; i++) {
		if ( rhs._materia[i] )
			this->_materia[i] = rhs._materia[i]->clone();
		else
			this->_materia[i] = nullptr;
	}
}

MateriaSource::~MateriaSource() {
	for ( uint i = 0; i < MATERIA_SIZE; i++) {
		if ( this->_materia[i] )
			delete this->_materia[i];
		else
			break ;
	}
	cout << "MateriaSource 🧙‍♂️ - Default destructor called" << endl;
}


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
MateriaSource &MateriaSource::operator=( MateriaSource const & rhs ) {
	if ( this != &rhs) {
		for ( uint i = 0; i < MATERIA_SIZE; i++) {
			if ( this->_materia[i] )
				delete this->_materia[i];
		}
		*(this->_materia) = *(rhs._materia);
	}
	return *this;
}


/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */
AMateria* MateriaSource::getMateria( uint idx ) const { return this->_materia[idx]; }


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
void MateriaSource::learnMateria( AMateria* mat) {
	if ( !mat )
		cout << "Materia's source doesn't exist" << endl ;
	if ( this->_nbMateria == MATERIA_SIZE ) {
		cout << "Knowledge capacity is full" << endl;
		delete mat;
	} else if ( this->_nbMateria < MATERIA_SIZE ) {
		this->_materia[this->_nbMateria]= mat;
		cout << mat->getType() << "'s power has been learned " << endl;
		this->_nbMateria++;
	}
}

AMateria* MateriaSource::createMateria( string const & type ) {
	AMateria* newMat = NULL;

	if ( this->_nbMateria == 0 || (type != "ice" && type != "cure"
		&& type != "thunder" && type!= "fire" && type != "dagger")) {
		cout << "[ " << type << " ] hasn't been learned yet " << endl;
		return newMat;
	}

	for ( uint i = 0; i < MATERIA_SIZE; i++ ) {
		if ( this->_materia[i]->getType() == type ) {
			cout << this->_materia[i]->getType() << " has been created " << endl;
			newMat = this->_materia[i]->clone();
			return newMat;
		}
	}
	return newMat;
}