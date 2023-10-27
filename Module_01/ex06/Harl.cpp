/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/11 15:57:04 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
Harl::Harl( ) { 
	_ptrDebug = &Harl::_debug;
	_ptrInfo = &Harl::_info;
	_ptrWarning = &Harl::_warning;
	_ptrError = &Harl::_error;

	_tabLevel[0] = "DEBUG";
	_tabLevel[1] = "INFO";
	_tabLevel[2] = "WARNING";
	_tabLevel[3] = "ERROR";
}
Harl::~Harl( ) { }


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
void Harl::complain( string level ) {
	int complaint;
	
	for (complaint = 0; complaint < 4; complaint++) {
		if (!level.compare(_tabLevel[complaint]))
			break;
	}
	
	switch (complaint) {
		case DEBUG:
			(this->*_ptrDebug)();
		case INFO:
			(this->*_ptrInfo)();
		case WARNING:
			(this->*_ptrWarning)();
		case ERROR:
			(this->*_ptrError)();
			break;
		default:
			cout << "[ Probably complaining about insignificant problems ]" << endl;
	}
}

void Harl::_debug( ) const {
	cout << "*[DEBUG]*" << endl;
	cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle"
		<< "-special-ketchup burger. \nI really do !\n" << endl;
}

void Harl::_info( ) const {
	cout << "*[INFO]*" << endl;
	cout << "I cannot believe adding extra bacon costs more money. \nYou didn’t "
		<< "put enough bacon in my burger ! \nIf you did, I wouldn’t be asking "
		<< "for more !\n" << endl;
}
void Harl::_warning( ) const {
	cout << "*[WARNING]*" << endl;
	cout << "I think I deserve to have some extra bacon for free. \nI’ve been "
		<< "coming for years whereas you started working here since last month.\n"
		<< endl;
}

void Harl::_error( ) const {
	cout << "*[ERROR]*" << endl;
	cout << "This is unacceptable ! \nI want to speak to the manager now.\n" << endl;
}