#include "Harl.hpp"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/10 08:15:58 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	for (int i = 0; i < 4; i++) {
		if (!level.compare(_tabLevel[i])) {
				switch (i) {
					case DEBUG:
						(this->*_ptrDebug)();
						break;
					case INFO:
						(this->*_ptrInfo)();
						break;
					case WARNING:
						(this->*_ptrWarning)();
						break;
					case ERROR:
						(this->*_ptrError)();
						break;
					default:
						break; };
			break; }
	}
}

void Harl::_debug( ) const {
	cout << "*[DEBUG]*" << endl;
	cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle"
		<< "-special-ketchup burger. \nI really do !" << endl;
}

void Harl::_info( ) const {
	cout << "*[INFO]*" << endl;
	cout << "I cannot believe adding extra bacon costs more money. \nYou didn’t "
		<< "put enough bacon in my burger ! \nIf you did, I wouldn’t be asking "
		<< "for more !" << endl;
}
void Harl::_warning( ) const {
	cout << "*[WARNING]*" << endl;
	cout << "I think I deserve to have some extra bacon for free. \nI’ve been "
		<< "coming for years whereas you started working here since last month."
		<< endl;
}

void Harl::_error( ) const {
	cout << "*[ERROR]*" << endl;
	cout << "This is unacceptable ! \nI want to speak to the manager now." << endl;
}