/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/27 09:14:43 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
Character::Character() : ICharacter(), _nbItems( 0 ), _nbDroppedIt( 0 ) {
	cout << "Character 🛡 - Default constructor called" << endl;
	this->_name = "Knight";
	for ( uint i = 0; i < INVENTORY_SIZE; i++) {
			this->_items[i] = nullptr;
		}
}

Character::Character( string const name ) : ICharacter(), _name( name ), _nbItems( 0 ), _nbDroppedIt( 0 ) {
	cout << "Character 🛡 [ " << this->_name << " ] - Parametric constructor called" << endl;
	for ( uint i = 0; i < INVENTORY_SIZE; i++) {
		this->_items[i] = nullptr;
	}
}

Character::Character( Character const & rhs ) {
	cout << "Character 🛡 [ " << rhs._name << " ] - Copy constructor called" << endl;
	this->_name = rhs.getName();
	this->_nbItems = rhs._nbItems;
	this->_nbDroppedIt = rhs._nbDroppedIt;
	for ( uint i = 0; i < INVENTORY_SIZE; i++) {
		if ( rhs._items[i] )
			this->_items[i] = rhs._items[i]->clone();
		else
			this->_items[i] = nullptr;
	}
}

Character::~Character() {
	cout << "Character 🛡 [ " << this->_name << " ] - Default destructor called" << endl;
	for ( uint i = 0; i < INVENTORY_SIZE; i++) {
		if ( this->_items[i] )
			delete this->_items[i];
	}

	if ( this->_nbDroppedIt > 0 ) {
		for ( uint i = this->_nbDroppedIt; i > 0; i--) {
			if ( this->_droppedIt[i - 1] != nullptr )
				delete this->_droppedIt[i - 1];
		}
	}
}


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
Character &Character::operator=( Character const & rhs ) {
	cout << "Character 🛡 [ " << rhs._name << " ] - Assignment operator called" << endl;
	for ( uint i = 0; i < INVENTORY_SIZE; i++) {
		if ( this->_items[i] ) {
			delete this->_items[i];
			this->_items[i] = nullptr;
		}
		else {
			this->_items[i] = nullptr;
			break ;
		}
	}

	if ( this != &rhs ) {
		for ( uint i = 0; i < INVENTORY_SIZE; i++) {
			if ( rhs._items[i] )
				this->_items[i] = rhs._items[i]->clone();
			else
				break ;
		}
		this->_name = rhs.getName();
		this->_nbItems = rhs._nbItems;
	}
	return *this;
}


/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */
string const &Character::getName() const { return this->_name; }
string const Character::getItem( uint idx ) const { return this->_items[idx]->getType(); }


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
void Character::displayInfos( ) {
	cout << "*** Character Infos ***" << endl;
	cout << "name: " << this->getName() << endl;
	cout << "nb items: " << this->_nbItems << endl;
	for ( uint i = 0; i < INVENTORY_SIZE; i++) {
		if ( this->_items[i] )
			cout << "slot " << i << ": " << this->getItem(i) << endl;
		else
			break ;
	}
	cout << "***********************" << endl;
}

void Character::equip( AMateria* m ) {
	if ( !m )
		cout << "Item doesn't exist" << endl;
	else if ( this->_nbItems == INVENTORY_SIZE )
		cout << this->getName() << "'s inventory is full" << endl;
	else if ( this->_nbItems < INVENTORY_SIZE ) {
		this->_items[this->_nbItems] = m;
		cout << this->getName() << " equips " << this->getItem(this->_nbItems)
		<< " in bandolier's slot " << this->_nbItems + 1 << endl;
		this->_nbItems++;
	}
}

void Character::itemTracker( uint idx ) {
	this->_droppedIt[_nbDroppedIt] = this->_items[idx];
	this->_nbDroppedIt++;
}

void Character::unequip( int idx ) {
	if ( this->_nbItems == 0 || idx < 0 || idx >= INVENTORY_SIZE)
		cout << this->getName() << " can't drop this item " << endl;
	else if ( this->_items[idx] ) {
		cout << this->getName() << " drops " << this->getItem(idx) << endl;
		itemTracker(idx);
		this->_items[idx] = nullptr;
		this->_nbItems--;
	}
}

void Character::use(int idx, ICharacter& target ) {
	if ( this->_nbItems == 0 || idx < 0 || idx > INVENTORY_SIZE)
		cout << this->getName() << " can't use this item" << endl;
	else if ( !this->_items[idx])
		cout << "No item to use in slot " << idx;
	else if ( this->_items[idx] )
		this->_items[idx]->use( target );
}