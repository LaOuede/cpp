/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/30 08:25:53 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WHATEVER_HPP__
# define __WHATEVER_HPP__

/*
SWAP :
	Inverts the values of two given arguments. Returns nothing.
*/
template <typename T> void swap( T &elemA, T &elemB) {
	if ( elemA != elemB ) {
		T tmp;
		tmp = elemA;
		elemA = elemB;
		elemB = tmp;
	}
}

/*
MIN :
	Compares the two values passed as arguments and returns the smaller of the two.
	of the two. If both are equivalent, then return the second.
*/
template <typename T>
T const &min( T const &elemA, T const &elemB ) {
	return ( elemA < elemB ? elemA : elemB );
}

/*
MAX :
	Compares the two values passed as arguments and returns the greater of the two.
	of the two. If both are equivalent, then return the second.
*/
template <typename T>
T const &max( T const &elemA, T const &elemB ) {
	return ( elemA > elemB ? elemA : elemB );
}

#endif //---------------------------------------------------------- WHATEVER.HPP