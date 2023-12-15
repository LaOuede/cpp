/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/03 12:43:30 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
RobotomyRequestForm::RobotomyRequestForm() : 
	AForm( "RobotomyRequestForm", 
		MIN_GRADE_SIGN_ROB, MIN_GRADE_EXEC_ROB ) {
	cout << "RobotomyRequestForm - Default constructor called" << endl;
}

RobotomyRequestForm::RobotomyRequestForm( string target ) : 
	AForm( "RobotomyRequestForm", 
		MIN_GRADE_SIGN_ROB, MIN_GRADE_EXEC_ROB ), _target( target ) {
	cout << "RobotomyRequestForm - Parametric constructor called" << endl;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & rhs ) : 
	AForm( rhs.getName(), rhs.getGradeToExec(), rhs.getGradeToSign() ) {
	*this = rhs;
	cout << "RobotomyRequestForm - Copy constructor called" << endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	cout << "RobotomyRequestForm - Default destructor called" << endl;
}


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
RobotomyRequestForm &RobotomyRequestForm::operator=( RobotomyRequestForm const &rhs ) {
	if ( this != &rhs ) {
		const_cast<string&>(this->_name) = rhs._name;
		this->_signed = rhs._signed;
		const_cast<int&>(this->_gradeToSign) = rhs._gradeToSign;
		const_cast<int&>(this->_gradeToExec) = rhs._gradeToExec;
	}
	return *this;
}

ostream &operator<<( ostream &o, RobotomyRequestForm const &rhs ) {
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
string const &RobotomyRequestForm::getTarget() const { return this->_target; }


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
void RobotomyRequestForm::execute( Bureaucrat const &executor ) const {
	try {
		executeCheck( executor );
	} catch( exception &e ) {
		cerr << e.what() << endl;
		return ;
	}
	cout << "Zzzzzzzzzzz ( ...anoying drill sound... )" << endl;
	srand(time(0));
	if ( rand() % 2 ) {
		cout << "🦾  RobotomyRequestForm has been executed successfully on " << this->_target << endl;
	} else {
		cout << "🛠  " << "RobotomyRequestForm executed on " << this->_target << " has failed" << endl;
	}
}