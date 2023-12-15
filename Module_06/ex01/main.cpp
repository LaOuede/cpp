/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/29 08:15:26 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int main( int argc, char **argv ) {
	(void) argv;
	if ( argc == 1 ) {
		Data test = {
			"Allo",
			42,
			'z',
			420.024f
		};

		// Print "test" infos
		printData( &test, "test" );

		// Serialize
		cout << C_ITA "\nStep 1 - Serialize" << endl;
		uintptr_t res = serialize( &test ) ;

		// Deserialize
		cout << C_ITA "\nStep 2 - Deserialize" << endl;
		Data *new_test = deserialize( res );

		// Print "new_test" infos
		printData( new_test, "new_test" );
	} else {
		cerr << "./Serialize: Bad input [No argument needed]";
	}
	return 0;
}