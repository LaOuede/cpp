/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/29 13:05:31 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"
#include "Tests.hpp"

int main(int argc, char **argv) {
	if (DEBUG) {
		runTests();
	} else {
		try {
			if ( argc != 2 ) {
				throw Conversion::BadArgumentNumber();
			}
			Conversion c( argv[1] );
			cout << c << endl;
		} catch ( exception &e ) {
			cerr << e.what() << endl;
		}
	}
	return 0;
}