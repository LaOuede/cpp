/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/03 12:36:18 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
Form::Form() : _name( "default_form" ), _signed( false ), _gradeToSign( MIN_GRADE ), _gradeToExec( MIN_GRADE ) {
	cout << "Form - Default constructor called" << endl;
}

Form::Form( string name, int toSign, int toExec ) :
	_name( name ), _gradeToSign( toSign ), _gradeToExec( toExec ) {
	_signed = false ;
	if ( _gradeToSign < MAX_GRADE || _gradeToExec < MAX_GRADE ) {
		throw GradeTooHighException();
	} else if ( _gradeToSign > MIN_GRADE || _gradeToExec > MIN_GRADE ) {
		throw GradeTooLowException();
	}
	cout << "Form - Parametric constructor called" << endl;
}

Form::Form( Form const & rhs ) : _gradeToSign( rhs._gradeToSign ), _gradeToExec( rhs._gradeToExec ) {
	cout << "Form - Copy constructor called" << endl;
	*this = rhs;
}

Form::~Form() {
	cout << "Form - Default destructor called" << endl;
}


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
Form &Form::operator=( Form const &rhs ) {
	if ( this != &rhs ) {
		const_cast<string&>(this->_name) = rhs._name;
		this->_signed = rhs._signed;
		const_cast<int&>(this->_gradeToSign) = rhs._gradeToSign;
		const_cast<int&>(this->_gradeToExec) = rhs._gradeToExec;
	}
	return *this;
}

ostream &operator<<( ostream &o, Form const &rhs ) {
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
string const &Form::getName() const { return this->_name; }
bool const &Form::getSigned() const { return this->_signed; }
int const &Form::getGradeToSign() const { return this->_gradeToSign; }
int const &Form::getGradeToExec() const { return this->_gradeToExec; }


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
void Form::beSigned( Bureaucrat &bur ) {
	if ( this->_signed == true) {
		cout << bur.getName() << " couldn't sign " << this->_name 
			<< " because this form is already signed" << endl;
		throw AlreadySignedException();
	} else if ( bur.getGrade() <= this->_gradeToSign ) {
		this->_signed = true ;
		cout << "📝 " << this->_name << " has been signed by " << bur.getName() << endl;
	} else {
		cout << bur.getName() << " couldn't sign " << this->_name 
			<< " because their grade is too low" << endl;
		throw GradeTooLowException();
	}
}


/* ************************************************************************** */
/* Exceptions                                                                 */
/* ************************************************************************** */
const char* Form::GradeTooHighException::what() const throw() {
	return C_BOL C_RED "Form::GradeTooHighException" C_WHT;
}

const char* Form::GradeTooLowException::what() const throw() {
	return C_BOL C_RED "Form::GradeTooLowException" C_WHT;
}

const char* Form::AlreadySignedException::what() const throw() {
	return C_BOL C_RED "Form::AlreadySignedException" C_WHT;
}