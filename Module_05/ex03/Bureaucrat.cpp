/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/03 08:47:38 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
Bureaucrat::Bureaucrat() : _name("John Doe"), _grade(150) {
	cout << "Bureaucrat - Default constructor called" << endl;
}

Bureaucrat::Bureaucrat( string const name, int grade ) : _name(name), _grade(grade) {
	if ( this->_grade > MIN_GRADE ) {
		throw GradeTooLowException();
	} else if ( this->_grade < MAX_GRADE ) {
		throw GradeTooHighException();
	}
	cout << "Bureaucrat - Parametric constructor called" << endl;
}

Bureaucrat::Bureaucrat( Bureaucrat const & rhs ) {
	cout << "Bureaucrat - Copy constructor called" << endl;
	*this = rhs;
}

Bureaucrat::~Bureaucrat() {
	cout << "Bureaucrat - Default destructor called" << endl;
}

/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
Bureaucrat &Bureaucrat::operator=( Bureaucrat const &rhs ) {
	cout << "Bureaucrat - Assignment operator called" << endl;
	if ( this != &rhs) {
		this->_grade = rhs._grade;
		const_cast<string&>(this->_name) = rhs._name;
	}
	return *this;
}

ostream &operator<<( ostream &o, Bureaucrat const &rhs ) {
	o << C_CYA "* " << rhs.getName() << "'s infos :" << endl;
	o << "* " << rhs.getName();
	o << ", bureaucrat grade ";
	o << rhs.getGrade() << endl;
	o << C_WHT;
	return o;
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */
string const &Bureaucrat::getName() const { return this->_name; }
int const &Bureaucrat::getGrade() const { return this->_grade; }


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
void Bureaucrat::incrementGrade() {
	if ( this->_grade == MAX_GRADE ) {
		throw GradeTooHighException();
	} else {
		this->_grade -= 1;
	}
}

void Bureaucrat::decrementGrade() {
	if ( this->_grade == MIN_GRADE ) {
		throw GradeTooLowException();
	} else {
		this->_grade += 1;
	}
}

void Bureaucrat::signForm( AForm &form ) {
	try {
		form.beSigned( *this );
	} catch( exception &e) {
		cerr << e.what() << endl;
	}
}

void Bureaucrat::executeForm( AForm const &form ) {
	try {
		form.execute( *this );
	} catch ( exception &e ) {
		cerr << e.what() << endl;
		return ;
	}
	cout << this->getName() << " executed " << form.getName() << endl;
}


/* ************************************************************************** */
/* Exceptions                                                                 */
/* ************************************************************************** */
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return C_BOL C_RED "Bureaucrat::GradeTooHighException" C_WHT;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return C_BOL C_RED "Bureaucrat::GradeTooLowException" C_WHT;
}