/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/03 12:43:41 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
PresidentialPardonForm::PresidentialPardonForm() : 
	AForm( "PresidentialPardonForm", 
		MIN_GRADE_SIGN_PRES, MIN_GRADE_EXEC_PRES ) {
	cout << "PresidentialPardonForm - Default constructor called" << endl;
}

PresidentialPardonForm::PresidentialPardonForm( string target ) : 
	AForm( "PresidentialPardonForm", 
		MIN_GRADE_SIGN_PRES, MIN_GRADE_EXEC_PRES ), _target( target ) {
	cout << "PresidentialPardonForm - Parametric constructor called" << endl;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & rhs ) : 
	AForm( rhs.getName(), rhs.getGradeToExec(), rhs.getGradeToSign() ) {
	*this = rhs;
	cout << "PresidentialPardonForm - Copy constructor called" << endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	cout << "PresidentialPardonForm - Default destructor called" << endl;
}


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
PresidentialPardonForm &PresidentialPardonForm::operator=( PresidentialPardonForm const &rhs ) {
	if ( this != &rhs ) {
		const_cast<string&>(this->_name) = rhs._name;
		this->_signed = rhs._signed;
		const_cast<int&>(this->_gradeToSign) = rhs._gradeToSign;
		const_cast<int&>(this->_gradeToExec) = rhs._gradeToExec;
	}
	return *this;
}

ostream &operator<<( ostream &o, PresidentialPardonForm const &rhs ) {
	o << C_CYA "* " << rhs.getName() << "'s infos :" << endl;
	o << "* Status: ";
	o << rhs.getSigned() << endl;
	o << "* Grade to sign: ";
	o << rhs.getGradeToSign() << endl;
	o << "* Grade to exec: ";
	o << rhs.getGradeToExec() << endl;
	o << C_WHT;
	return o;
}


/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */
string const &PresidentialPardonForm::getTarget() const { return this->_target; }


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
void PresidentialPardonForm::execute( Bureaucrat const &executor ) const {
	try {
		executeCheck( executor );
	} catch( exception &e ) {
		cerr << e.what() << endl;
		return ;
	}
	cout << "🎁 " << this->getTarget() << " has been forgiven by Zaphod Beeblebrox" << endl;
}