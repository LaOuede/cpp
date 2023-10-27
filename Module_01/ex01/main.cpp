/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/11 15:50:18 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, string name ) ;

bool checkName(string arg) {
	if (arg.size() > 20) {
		cerr << "Usage: error: argv[2] size must be < to 20 characters" << endl;
		return false;
	}
	return true;
}

bool checkSize(string arg) {
	if (arg.size() > 10) {
		cerr << "Usage: error: argv[1] must be < to INT_MAX" << endl;
		return false;
	}
	for (size_t i = 0; i < arg.size(); i++) {
		if (!isnumber(arg[i])) {
			cerr << "Usage: error: argv[1] must be a number" << endl;
			return false;
		}
	}
	return true;
}

int main (int argc, char **argv) {
	if (argc == 3 && checkSize(argv[1]) && checkName(argv[2])) {
		int hordeSize = std::stoi(argv[1]);
		Zombie *horde = zombieHorde(hordeSize, argv[2]);
		for (int i = 0; i < hordeSize; i++) {
			horde[i].annouce();
		}
		delete [] horde; // all zombies are destroyed;
		return 0;
	} else if (argc != 3) {
		cerr << "Usage: error: 2 arguments needed <horde_size> <name>" << endl;
	}
	return 0;
}