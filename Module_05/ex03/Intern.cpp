/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/03 08:48:35 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
Intern::Intern() {
	cout << "Intern - Default constructor called" << endl;
}

Intern::Intern( Intern const & rhs ) {
	cout << "Intern - Copy constructor called" << endl;
	*this = rhs;
}

Intern::~Intern() {
	cout << "Intern - Default destructor called" << endl;
}

/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
Intern &Intern::operator=( Intern const &rhs ) {
	cout << "Intern - Assignment operator called" << endl;
	if ( this != &rhs) {
		*this = rhs;
	}
	return *this;
}


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
AForm *Intern::makeSCF( string target ) {
	return new ShrubberyCreationForm( target );
}

AForm *Intern::makeRRF( string target ) {
	return new RobotomyRequestForm( target );
}

AForm *Intern::makePPF( string target ) {
	return new PresidentialPardonForm( target );
}

AForm *Intern::makeForm( string formName, string formTarget ) {

	string forms[3] = { 
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm *(Intern::*formType[3])( string target ) = {
		&Intern::makeSCF,
		&Intern::makeRRF,
		&Intern::makePPF,
	};

	for ( int i = 0; i < 3; i++) {
		if ( formName == forms[i] ) {
				cout << "👨‍💻 Intern creates " << forms[i] << endl;
				return (this->*formType[i])( formTarget );
			}
	}

	cout << "Intern couldn't create a form because there was an error with the form name" << endl;
	throw BadFormNameInformation();
}

/* ************************************************************************** */
/* Exceptions                                                                 */
/* ************************************************************************** */
const char* Intern::BadFormNameInformation::what() const throw() {
	return C_BOL C_RED "Intern::BadFormNameInformation" C_WHT;
}