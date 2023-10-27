/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/27 09:17:53 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
FragTrap::FragTrap() : ClapTrap() {
	this->_name = "John Doe";
	this->_hp = FRAG_HP;
	this->_energy = FRAG_EP;
	this->_atkDamage = FRAG_DMG;
	cout << "💣FragTrap..." << this->_name 
		<< " is here, ready to explode ! - Default constructor called" << endl;
}

FragTrap::FragTrap( string const name ) : ClapTrap( name ) {
	this->_name = name;
	this->_hp = FRAG_HP;
	this->_energy = FRAG_EP;
	this->_atkDamage = FRAG_DMG;
	cout << "💣FragTrap..." << this->_name 
		<< " is here, ready to explode ! - Parametric constructor called" << endl;
}

FragTrap::FragTrap( FragTrap const & rhs ) : ClapTrap() {
	*this = rhs;
	_name.append(".copy");
	cout << "💣FragTrap..." << this->_name 
		<< " is here, ready to explode ! - Copy constructor called" << endl;
}

FragTrap::~FragTrap() {
	cout << "💥FragTrap... " << this->_name << " exploded ! - Destructor called" << endl;
}


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
FragTrap &FragTrap::operator=( FragTrap const & rhs ) {
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
void FragTrap::attack( const string & target ) {
	if ( isAlive() && hasEnergy() ) {
		cout << "💥FragTrap " << this->_name << " exploding toward " << target 
			<< ", causing " << this->_atkDamage << " damage!" << endl;
		this->_energy--;
	} else
		displayStatus();
}

void FragTrap::highFivesGuys( ) {
	if (this->isAlive())
		cout << this->_name << " really wants a high fives!🖐 " << endl;
	else
		displayStatus();
}
