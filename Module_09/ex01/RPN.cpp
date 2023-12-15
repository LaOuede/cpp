/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/12/13 10:13:14 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
RPN::RPN() {}
RPN::RPN( string input ): _input( input ) {}
RPN::RPN( RPN const &rhs ) { *this = rhs; }
RPN::~RPN() {}


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
RPN &RPN::operator=( RPN const &rhs ) {
	if ( this != &rhs ) {
		this->_input = rhs._input;
		this->_data_stack = rhs._data_stack;
	}
	return *this;
}


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
// STEP 1 - INPUT PARSING
bool RPN::isOperator( char const &c ) {
	char operators[4] = { '+', '-', '*', '/' };

	for ( int i = 0; i < 4; i++ ) {
		if ( c == operators[i] ) {
			this->_operator = i + 1;
			return true;
		}
	}
	this->_operator = 0;
	return false;
}

void RPN::checkTokenThrowCalcul() {
	int i = -1;
	string::iterator it;

	for ( it = this->_input.begin(); it != this->_input.end(); it++ ) {
		if ( !(++i & 1) ) {
			if ( isspace(*it) ) {
				throw runtime_error("Error: invalid syntax");
			} else if ( isdigit(*it) ) {
				this->_data_stack.push( (int)*it - 48 );
			} else if ( !isspace(*it) && isOperator(*it) ) {
				tryOperation();
			}
		}
	}
}

void RPN::checkString() {
	size_t found = this->_input.find_first_not_of("+-/*0123456789 ");

	if ( found != string::npos ) {
		throw runtime_error("Error: invalid syntax / Forbidden character");
	}
}

void RPN::checkInput() {
	if ( this->_input.empty() ) {
		throw runtime_error("Error: One argument needed");
	}
}

// STEP 2 - CALCUL
void RPN::doOperation( _operands &nbs ) {
	switch(this->_operator) {
		case PLUS:
			this->_data_stack.push( nbs.operand1 + nbs.operand2 );
			break;
		case MIN:
			this->_data_stack.push( nbs.operand1 - nbs.operand2 );
			break;
		case MULT:
			this->_data_stack.push( nbs.operand1 * nbs.operand2 );
			break;
		case DIV:
			if ( !nbs.operand2 ) {
				throw runtime_error( "Error: can't perform operation / divider is 0");
			} else {
				this->_data_stack.push( nbs.operand1 / nbs.operand2 );
			}
			break;
	}
}

RPN::_operands RPN::extractOperands() {
	_operands nbs;

	nbs.operand2 = this->_data_stack.top();
	this->_data_stack.pop();

	nbs.operand1 = this->_data_stack.top();
	this->_data_stack.pop();

	return nbs;
}

void RPN::tryOperation() {
	_operands nbs;

	if ( this->_data_stack.size() >= 2 ) {
		nbs = extractOperands();
		doOperation( nbs );
	} else {
		throw runtime_error( "Error: invalid syntax / Not enough operand");
	}
}

// STEP 3 - VALIDATION
void RPN::checkRest() {
	if ( this->_data_stack.size() > 1 ) {
		throw runtime_error( "Error: invalid syntax / Remaining");
	} else {
		cout << this->_data_stack.top() << endl;
	}
}

// MAIN FUNCTION
void RPN::calculator( void ) {
	checkInput();
	checkString();
	checkTokenThrowCalcul();
	checkRest();
}