/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/23 18:57:56 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Tests.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	TITLE( "----------------------- Test 1 -----------------------");
	TEST( "----------------------- Const. -----------------------");
	AAnimal* tabAnimals[100];

	for (int i = 0; i < 100; i++) {
		cout << C_GRN << "tabAnimals: " << i << C_WHT << endl;
		if (i < 50)
			tabAnimals[i] = new Dog();
		else
			tabAnimals[i] = new Cat();
		tabAnimals[i]->makeSound();
	}

	TEST( "----------------------- Dest. ------------------------");
	for (int i = 0; i < 100; i++) {
		cout << C_GRN << "tabAnimals: " << i << C_WHT << endl;
		delete tabAnimals[i];
	}

	runTests();
	return 0;
}