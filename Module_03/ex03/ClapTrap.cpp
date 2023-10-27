/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/27 09:18:19 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
ClapTrap::ClapTrap() : _name( "John Doe" ), _hp( CLAP_HP ), _energy( CLAP_EP ),
	 _atkDamage( CLAP_DMG ) {
	cout << this->_name << " - Default constructor called" << endl;
}

ClapTrap::ClapTrap( string const name ) : _name( name ), _hp( CLAP_HP ),
	 _energy( CLAP_EP ), _atkDamage( CLAP_DMG ) {
	cout << this->_name << " - Parametric constructor called" << endl;
}

ClapTrap::ClapTrap( ClapTrap const & rhs ) {
	*this = rhs;
	_name.append(".copy");
	cout << this->_name << " - Copy constructor called" << endl;
}

ClapTrap::~ClapTrap() {
	cout << this->_name << " - Destructor called" << endl;
}


/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */
string const &ClapTrap::getName() const { return this->_name; }
int const &ClapTrap::getHP() const { return this->_hp; }
int const &ClapTrap::getEnergy() const { return this->_energy; }
int const &ClapTrap::getAtkDamage() const { return this->_atkDamage; }

void ClapTrap::setHP( int const &hp ) { this->_hp = hp; }


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
ClapTrap &ClapTrap::operator=( ClapTrap const & rhs ) {
	if ( this != &rhs ) {
		this->_name = rhs.getName();
		this->_hp = rhs.getHP();
		this->_energy = rhs.getEnergy();
		this->_atkDamage = rhs.getAtkDamage();
	}
	return *this;
}


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
void ClapTrap::attack( const string & target ) {
	if ( this->isAlive() && this->hasEnergy() ) {
		cout << this->_name << " is attacking " << target << ", causing " 
			<< this->_atkDamage << " damage!🗡️" << endl;
		this->_energy--;
	} else
		displayStatus();
}

void ClapTrap::takeDamage( uint amount ) {
	if ( this->isAlive() && this->hasEnergy() ) {
		this->setHP( this->_hp - amount );
		cout << this->_name << " is receiving " << amount << " damage!🩸" << endl;
	} else
		displayStatus();
}

void ClapTrap::beRepaired( uint amount ) {
	if ( this->isAlive() && this->hasEnergy() ) {
		this->setHP( this->_hp + amount );
		this->_energy--;
		cout << this->_name << " is healing for " << amount << " HP! 🧪" << endl;
	} else
		displayStatus();
}

bool ClapTrap::isAlive() {
	return this->_hp > 0;
}

bool ClapTrap::hasEnergy() {
	return this->_energy > 0;
}

void ClapTrap::displayStatus() {
	if ( !this->isAlive() )
		cout << "Sadly, " << this->_name << " is dead...💀" << endl;
	else if ( !this->hasEnergy() )
		cout << "Unfortunately, " << this->_name << " ran out of energy...🔋" << endl;
}