/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/27 09:19:24 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* ************************************************************************** */
/* Static                                                                     */
/* ************************************************************************** */
int ScavTrap::_scav_hp = SCAV_HP;
int ScavTrap::_scav_ep = SCAV_EP;
int ScavTrap::_scav_dmg = SCAV_DMG;


/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
ScavTrap::ScavTrap() : ClapTrap(), _guardMode( false ) {
	this->_name = "John Doe";
	this->_hp = SCAV_HP;
	this->_energy = SCAV_EP;
	this->_atkDamage = SCAV_DMG;
	cout << "🤖Bip Bip ScavTrap... " << this->_name 
		<< " - Default constructor called" << endl;
}

ScavTrap::ScavTrap( string const name ) : ClapTrap( name ), _guardMode( false ) {
	this->_name = name;
	this->_hp = SCAV_HP;
	this->_energy = SCAV_EP;
	this->_atkDamage = SCAV_DMG;
	cout << "🤖Bip Bip ScavTrap... " << this->_name 
		<< " - Parametric constructor called" << endl;
}

ScavTrap::ScavTrap( ScavTrap const & rhs ) : ClapTrap() {
	*this = rhs;
	_name.append(".copy");
	cout << "🤖Bip Bip ScavTrap... " << this->_name 
		<< " - Copy constructor called" << endl;
}

ScavTrap::~ScavTrap() {
	cout << "🤖Bip Bip ScavTrap... " << this->_name << " - Destructor called" << endl;
}


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
ScavTrap &ScavTrap::operator=( ScavTrap const & rhs ) {
	if ( this != &rhs ) {
		this->_name = rhs.getName();
		this->_hp = rhs.getHP();
		this->_energy = rhs.getEnergy();
		this->_atkDamage = rhs.getAtkDamage();
		this->_guardMode = rhs._guardMode;
	}
	return *this;
}

/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
void ScavTrap::attack( const string & target ) {
	if ( this->isAlive() && this->hasEnergy() && !this->isGuardian() ) {
		cout << "🤖Bip Bip ScavTrap... " << this->_name << " attacking " 
			<< target << ", causing " << this->_atkDamage << " damage!" << endl;
		this->_energy--;
	} else
		displayStatus();
}

void ScavTrap::beRepaired( unsigned int amount ) {
	if ( this->isAlive() && this->hasEnergy() && !this->isGuardian() ) {
		this->setHP( this->_hp + amount );
		this->_energy--;
		cout << this->_name << " is healing for " << amount << " HP! 🧪" << endl;
	} else
		displayStatus();
}

void ScavTrap::displayStatus() {
	if ( !this->isAlive() )
		cout << "Sadly, " << this->_name << " is dead...💀" << endl;
	else if ( !this->hasEnergy() )
		cout << "Unfortunately, " << this->_name << " ran out of energy...🔋" << endl;
	else if ( this->isGuardian() )
		cout << "🤖Bip Bip ScavTrap... " << this->_name 
			<< " can't do, Gate Keeper mode is activated!🛡️" << endl;
}

void ScavTrap::guardGate( ) {
	(this->_guardMode ? this->_guardMode = false : this->_guardMode = true);
	if (this->_guardMode)
		cout << "🤖Bip Bip ScavTrap... " << this->_name 
			<< ": Gate Keeper mode activated!" << endl;
	else
		cout << "🤖Bip Bip ScavTrap... " << this->_name 
			<< ": Gate Keeper mode desactivated!" << endl;
	return ;
}

bool ScavTrap::isGuardian( ) {
	return this->_guardMode == 1;
}

void ScavTrap::takeDamage( unsigned int amount ) {
	if ( this->isAlive() && this->hasEnergy() && !this->isGuardian() ) {
		this->setHP( this->_hp - amount );
		cout << this->_name << " is receiving " << amount << " damage!🩸" << endl;
	} else
		displayStatus();
}