/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/27 09:37:17 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
Brain::Brain() {
	cout << "Brain 🧠 - Default constructor called" << endl;
}

Brain::Brain( Brain const & rhs ) {
	cout << "Brain 🧠 - Copy constructor called" << endl;
	for (int i = 0; i < NB_IDEAS; i++)
		this->_ideas[i] = rhs._ideas[i];
}

Brain::~Brain() {
	cout << "Brain 🧠 - Default destructor called" << endl;
}


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
Brain &Brain::operator=( Brain const & rhs ) {
	if ( this != &rhs ) {
		for (int i = 0; i < NB_IDEAS; i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	return *this;
}


/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */
string const &Brain::getIdea( int i ) const { return this->_ideas[i]; }
Brain* Brain::copyBrain() { return ( new Brain(*this)); }
void Brain::setIdea( string idea, int i ) { this->_ideas[i] = idea; }


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
void Brain::fillIdeas( string type ) {
	std::fstream file;
	string line;
	if (type == "Cat")
		file.open("ideasCat.txt");
	else
		file.open("ideasDog.txt");
	if (!file.is_open())
		return ;
	for (int i = 0; i < NB_IDEAS; i++) {
		getline(file, line);
		this->_ideas[i] = line;
	}
	file.close();
}