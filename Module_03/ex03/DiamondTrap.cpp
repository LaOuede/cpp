/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/27 09:18:28 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
DiamondTrap::DiamondTrap() {
	ClapTrap::_name.append("_clap_trap");
	this->_name = "John Doe";
	this->_hp = _frag_hp;
	this->_energy = _scav_ep;
	this->_atkDamage = _frag_dmg;
	cout << "💎DiamondTrap... ! " << this->_name << " - Default constructor called" << endl;
}

DiamondTrap::DiamondTrap( string const name ) : ClapTrap( name ), ScavTrap( name ), FragTrap( name ) {
	ClapTrap::_name.append("_clap_trap");
	this->_name = name;
	this->_hp = _frag_hp;
	this->_energy = _scav_ep;
	this->_atkDamage = _frag_dmg;
	cout << "💎DiamondTrap... " << this->_name << " - Parametric constructor called" << endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const & rhs ) {
	*this = rhs;
	_name.append(".copy");
	cout << "💎DiamondTrap... " << this->_name << " - Copy constructor called" << endl;
}

DiamondTrap::~DiamondTrap() {
	cout << "💎DiamondTrap... " << this->_name << " - Destructor called" << endl;
}


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
DiamondTrap &DiamondTrap::operator=( DiamondTrap const & rhs ) {
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
void DiamondTrap::whoAmI( ) {
	cout << "📣 Who I am ? My name is: " << this->_name << endl;
	cout << "📣 ClapTrap::_name: " << ClapTrap::getName() << endl;
}