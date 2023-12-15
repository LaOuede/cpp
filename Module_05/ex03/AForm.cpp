/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/03 12:37:43 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
AForm::AForm() : _name( "default" ), _signed( false ), _gradeToSign( 150 ), _gradeToExec( 150 ) {
	cout << "AForm - Default constructor called" << endl;
}

AForm::AForm( string name, int toSign, int toExec ) :
	_name( name ), _gradeToSign( toSign ), _gradeToExec( toExec ) {
	_signed = false ;
	if ( _gradeToSign < MAX_GRADE || _gradeToExec < MAX_GRADE ) {
		throw GradeTooHighException();
	} else if ( _gradeToSign > MIN_GRADE || _gradeToExec > MIN_GRADE ) {
		throw GradeTooLowException();
	}
	cout << "Form - Parametric constructor called" << endl;
}

AForm::AForm( AForm const & rhs ) : _gradeToSign( rhs._gradeToSign ), _gradeToExec( rhs._gradeToExec ) {
	cout << "AForm - Copy constructor called" << endl;
	*this = rhs;
}

AForm::~AForm() {
	cout << "AForm - Default destructor called" << endl;
}


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
AForm &AForm::operator=( AForm const &rhs ) {
	if ( this != &rhs ) {
		const_cast<string&>(this->_name) = rhs._name;
		this->_signed = rhs._signed;
		const_cast<int&>(this->_gradeToSign) = rhs._gradeToSign;
		const_cast<int&>(this->_gradeToExec) = rhs._gradeToExec;
	}
	return *this;
}

ostream &operator<<( ostream &o, AForm const &rhs ) {
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
string const &AForm::getName() const { return this->_name; }
bool const &AForm::getSigned() const { return this->_signed; }
int const &AForm::getGradeToSign() const { return this->_gradeToSign; }
int const &AForm::getGradeToExec() const { return this->_gradeToExec; }


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
void AForm::beSigned( Bureaucrat &bur ) {
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
void AForm::executeCheck( Bureaucrat const &executor ) const {
	if ( !this->_signed ) {
		throw FormNotSignedException();
	} else if ( executor.getGrade() > this->_gradeToExec ) {
		throw GradeTooLowException();
	}
}

/* ************************************************************************** */
/* Exceptions                                                                 */
/* ************************************************************************** */
const char* AForm::GradeTooHighException::what() const throw() {
	return C_BOL C_RED "Form::GradeTooHighException" C_WHT;
}

const char* AForm::GradeTooLowException::what() const throw() {
	return C_BOL C_RED "Form::GradeTooLowException" C_WHT;
}

const char* AForm::AlreadySignedException::what() const throw() {
	return C_BOL C_RED "Form::AlreadySignedException" C_WHT;
}

const char* AForm::FormNotSignedException::what() const throw() {
	return C_BOL C_RED "Execute::FormNotSignedException" C_WHT;
}