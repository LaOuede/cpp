/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/10 08:15:58 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *newZombie( std::string name );
void randomChump( std::string name );

int main () {
	// 1- Zombie class
	Zombie zombie1("Frankenstein");
	zombie1.annouce();

	// 2- new method (newZombie function)
	Zombie* zombie2 = newZombie("Ed");
	zombie2->annouce();
	delete zombie2;

	// 3- randomChump function
	randomChump("Solomon");

	return 0;
}