/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/03 12:43:49 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
ShrubberyCreationForm::ShrubberyCreationForm() : 
	AForm( "ShrubberyCreationForm", 
		MIN_GRADE_SIGN_SHR, MIN_GRADE_EXEC_SHR ) {
	cout << "ShrubberyCreationForm - Default constructor called" << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( string target ) : 
	AForm( "ShrubberyCreationForm", 
		MIN_GRADE_SIGN_SHR, MIN_GRADE_EXEC_SHR ), _target( target ) {
	cout << "ShrubberyCreationForm - Parametric constructor called" << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & rhs ) : 
	AForm( rhs.getName(), rhs.getGradeToExec(), rhs.getGradeToSign() ) {
	*this = rhs;
	cout << "ShrubberyCreationForm - Copy constructor called" << endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	cout << "ShrubberyCreationForm - Default destructor called" << endl;
}


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
ShrubberyCreationForm &ShrubberyCreationForm::operator=( ShrubberyCreationForm const &rhs ) {
	if ( this != &rhs ) {
		const_cast<string&>(this->_name) = rhs._name;
		this->_signed = rhs._signed;
		const_cast<int&>(this->_gradeToSign) = rhs._gradeToSign;
		const_cast<int&>(this->_gradeToExec) = rhs._gradeToExec;
	}
	return *this;
}

ostream &operator<<( ostream &o, ShrubberyCreationForm const &rhs ) {
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
string const &ShrubberyCreationForm::getTarget() const { return this->_target; }


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
void ShrubberyCreationForm::execute( Bureaucrat const &executor ) const {
	try {
		executeCheck( executor );
	} catch( exception &e ) {
		cerr << e.what() << endl;
		return ;
	}
	string outfileName = this->_target + "_shrubbery";
	ofstream ofs( outfileName );

	if ( !ofs.is_open() ) {
		cerr << "Usage: Error: " << outfileName << " can't be opened" << endl;
		return ;
	}

	ofs << ASCII_TREES << endl;
	cout << "🌳 ShrubberyCreationForm has been executed with " << this->_target << " as target" << endl;
}