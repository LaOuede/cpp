/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/10 08:16:42 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, string name ) {
	if (N > 0) {
		Zombie* zombie = new Zombie[N];

		for (int i = 0; i < N; i++) {
			zombie[i].setName(name);
		}
		return zombie;
	}
	cout << "Usage: error: argv[1] must be > 0" << endl;
	return NULL;
}

