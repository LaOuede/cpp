/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/06 11:12:05 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // std::cout, std::cin, std::endl
#include <iomanip> // std::setw
#include <string>
#include "Contact.hpp"

using std::cin;
using std::cout;
using std::endl;

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
Contact::Contact( void ) { }
Contact::~Contact( void ) { }

/* ************************************************************************** */
/* Getters                                                                    */
/* ************************************************************************** */
const std::string &Contact::get_firstName ( void ) const { return this->_m_firstName; }
const std::string &Contact::get_lastName ( void ) const { return this->_m_lastName; }
const std::string &Contact::get_nickname ( void ) const { return this->_m_nickname; }
const std::string &Contact::get_phoneNumber ( void ) const { return this->_m_phoneNumber; }
const std::string &Contact::get_darkestSecret ( void ) const { return this->_m_darkestSecret; }

/* ************************************************************************** */
/* Setters                                                                    */
/* ************************************************************************** */
void Contact::set_firstName (const std::string &firstName) { this->_m_firstName = firstName; }
void Contact::set_lastName (const std::string &lastName) { this->_m_lastName = lastName; }
void Contact::set_nickname (const std::string &nickname) { this->_m_nickname = nickname; }
void Contact::set_phoneNumber (const std::string &phoneNumber) { this->_m_phoneNumber = phoneNumber; }
void Contact::set_darkestSecret (const std::string &darkestSecret) { this->_m_darkestSecret = darkestSecret; }