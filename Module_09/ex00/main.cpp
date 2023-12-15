/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/12/06 07:49:18 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	try {
		if ( argc != 2 ) {
			throw BitcoinExchange::UnableToOpenFile();
		}
		BitcoinExchange btc( argv[1] );
		btc.converter();
	} catch ( exception &e ) {
		cerr << e.what() << endl;
	}
	return 0;
}