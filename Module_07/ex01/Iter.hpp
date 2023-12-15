/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/30 12:07:21 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ITER_HPP__
# define __ITER_HPP__	

# include <iostream>

using std::cout;
using std::endl;

/*
ITER :
	Takes 3 parameters and returns nothing.
	- The first parameter is the address of an array.
	- The second is the size of the array.
	- The third is a function to be called on each element of the array
	*/
template <typename T>
void iter( T *tab, size_t sizeTab, void ( *f ) ( T& ) ) {
	for ( size_t i = 0; i < sizeTab; i++) {
		f( tab[i] );
	}
}

// Others function - Increment
template <typename T>
void increment( T &content ) {
	content++;
}

// Others function - Decrement
template <typename T>
void decrement( T &content ) {
	content--;
}

// Others functions- Print
template <typename T>
void print( T &content ) {
	cout << content << endl;
}

#endif //-------------------------------------------------------------- ITER.HPP