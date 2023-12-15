/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/29 12:56:50 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main( int argc, char **argv ) {
	(void) argv;
	if ( argc == 1 ) {
		// Step 1: Generate a Base
		cout << C_ITA C_BLU "Generating a random Base..." C_WHT << endl;
		Base *test = generate();

		// Step 2: Identify (pointer)
		cout << C_ITA C_BLU "\nIdentifying element (pointer)..." C_WHT << endl;
		identify( test );

		// Step 3: Identify (reference)
		cout << C_ITA C_BLU "\nIdentifying element (reference)..." C_WHT << endl;
		identify( *test );

		// Step 4: Delete Base
		delete( test );
	} else {
		cerr << "./Base: Bad input [No argument needed]";
	}
	return 0;
}