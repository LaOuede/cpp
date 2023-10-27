/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/27 08:39:07 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
Zombie::Zombie ( string name ) : _m_name(name) { }

Zombie::~Zombie() {
	cout << this->_m_name << " has been destroyed 💀" << endl;
}


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
void Zombie::annouce() {
	cout << this->_m_name << ": BraiiiiiiinnnzzzZ... 🧠" << endl;
}