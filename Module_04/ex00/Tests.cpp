/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/23 19:10:04 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"

void runTests() {
	{
		TITLE( "----------------------- Test 1 -----------------------");
		TEST( "Subject tests");
		TEST( "----------------------- Const. -----------------------");
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		TEST( "------------------------ Type ------------------------");
		cout << meta->getType() << " " << endl;
		cout << j->getType() << " " << endl;
		cout << i->getType() << " " << endl;
		TEST( "------------------------ Sound -----------------------");
		i->makeSound();
		j->makeSound();
		meta->makeSound();
		TEST( "----------------------- Dest. ------------------------");
		delete i;
		delete j;
		delete meta;
	}
		{
		TITLE( "----------------------- Test 2 -----------------------");
		TEST( "Copy test");
		TEST( "----------------------- Const. -----------------------");
		Dog *doggo = new Dog();
		Dog dog(*doggo);
		TEST( "----------------------- Doggo ------------------------");
		cout << doggo->getType() << " " << endl;
		doggo->makeSound();
		delete doggo;
		TEST( "------------------------ Dog -------------------------");
		cout << dog.getType() << " " << endl;
		dog.makeSound();
	}
	{
		TITLE( "----------------------- Test 3 -----------------------");
		TEST( "Wrong categorie tests");
		TEST( "----------------------- Const. -----------------------");
		const WrongAnimal* meta = new WrongAnimal();
		const Animal* j = new Dog();
		const WrongAnimal* i = new WrongCat();
		TEST( "------------------------ Type ------------------------");
		cout << meta->getType() << " " << endl;
		cout << j->getType() << " " << endl;
		cout << i->getType() << " " << endl;
		TEST( "------------------------ Sound -----------------------");
		i->makeSound();
		j->makeSound();
		meta->makeSound();
		TEST( "----------------------- Dest. ------------------------");
		delete i;
		delete j;
		delete meta;
	}
	{
		TITLE( "----------------------- Test 4 -----------------------");
		TEST( "Wrong categorie tests only");
		TEST( "----------------------- Const. -----------------------");
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* cat = new WrongCat();
		TEST( "------------------------ Type ------------------------");
		cout << meta->getType() << endl;
		cout << cat->getType() << endl;
		TEST( "------------------------ Sound -----------------------");
		meta->makeSound();
		cat->makeSound();
		TEST( "----------------------- Dest. ------------------------");
		delete cat;
		delete meta;
		TITLE( "--------------------- End Tests ----------------------");
	}
}