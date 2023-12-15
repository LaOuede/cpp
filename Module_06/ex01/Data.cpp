/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/30 08:08:23 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

/*
Reinterpret cast:
- Allows reinterpretation, upcast and downcast.
- This is the most permissive cast, so you can reinterpret any address to 
any other address, with all the consequences that may entail.
- Common use case = retyping.

Identity conversion: after conversion, the base value retains the same bits in 
the same order. No real conversion has taken place during the cast.
This is known as reinterpretation.
*/

/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
// serialize takes a pointer and converts it to the unsigned integer type uintptr_t
uintptr_t serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

/*
	deserialize takes an unsigned integer type uintptr_t as a parameter and 
	converts it to a pointer to Data
*/
Data *deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}

void printData( Data *x, string dataName ) {
	cout << C_BLU "\n----- " << dataName << " INFOS" C_WHT << endl;
	cout << C_BOL C_BLU "Data adr: " C_WHT << &x << endl;
	cout << C_BOL C_BLU "Data str: " C_WHT << x->str << endl;
	cout << C_BOL C_BLU "Data int: " C_WHT << x->nb << endl;
	cout << C_BOL C_BLU "Data chr: " C_WHT << x->c << endl;
	cout << C_BOL C_BLU "Data flt: " C_WHT << x->f << "f" << endl;
}