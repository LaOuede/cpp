/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/29 17:13:49 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

/*
Dynamic cast:
- This is the only cast that takes place at runtime (unlike the others, which are performed
at compile time -> so they're static).
- Another peculiarity: it will only work in the case of polymorphic instances
instance (at least one virtual method to use cast on it).
*/


/* ************************************************************************** */
/* Destructor                                                                 */
/* ************************************************************************** */
Base::~Base() {}


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
// generate randomly creates an instance of A, B or C and returns it as a pointer to Base.
Base *generate() {
	srand( time(0) );
	int type = rand() % 3;

	switch( type ) {
		case 0:
			cout << "Type of the generated Base: " << C_BOL C_BLU "A" C_WHT << endl;
			return new A;
		case 1:
			cout << "Type of the generated Base: " << C_BOL C_BLU "B" C_WHT << endl;
			return new B;
		default:
			cout << "Type of the generated Base: " << C_BOL C_BLU "C" C_WHT << endl; 
			return new C;
	}
}

// Identify pointer displays the true type of the object pointed to by p: "A", "B" or "C".
void identify( Base *p ) {
	if ( dynamic_cast<A*>(p) ) {
		cout << "True object type pointed by 'p' is: " << C_BOL C_BLU "A" C_WHT << endl;
	} else if ( dynamic_cast<B*>(p) ) {
		cout << "True object type pointed by 'p' is: " << C_BOL C_BLU "B" C_WHT<< endl;
	} else if ( dynamic_cast<C*>(p) ) {
		cout << "True object type pointed by 'p' is: " << C_BOL C_BLU "C" C_WHT << endl;
	}
}

/*
Identify reference displays the true type of the object pointed to by p: "A", "B" or "C".
In the case of a reference, we can't return a NULL pointer, since a reference can't be NULL.
So we'll throw a "bad_cast" exception.
*/
void identify(Base &p) {
	try {
		Base tryA = dynamic_cast<A&>(p);
		cout << "True object type pointed by 'p' is: " << C_BOL C_BLU "A" C_WHT << endl;
	} catch( bad_cast &bc ) {
		cerr << "Conversion is NOT OK: " << bc.what() << std::endl;
	}
	try {
		Base tryB = dynamic_cast<B&>(p);
		cout << "True object type pointed by 'p' is: " << C_BOL C_BLU "B" C_WHT << endl;
	} catch( bad_cast &bc ) {
		cerr << "Conversion is NOT OK: " << bc.what() << std::endl;
	}
	try {
		Base tryC = dynamic_cast<C&>(p);
		cout << "True object type pointed by 'p' is: " << C_BOL C_BLU "C" C_WHT << endl;
	} catch( bad_cast &bc ) {
		cerr << "Conversion is NOT OK: " << bc.what() << std::endl;
	}
}