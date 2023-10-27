/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/23 19:03:02 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"

void runTests() {
	{
		TITLE( "\n----------------------- Test 2 -----------------------");
		TEST( "Subject tests");
		TEST( "----------------------- Const. -----------------------");
		const AAnimal* i = new Dog();
		const AAnimal* j = new Cat();
		TEST( "------------------------ Type ------------------------");
		cout << i->getType() << endl;
		cout << j->getType() << endl;
		TEST( "------------------------ Sound -----------------------");
		i->makeSound();
		j->makeSound();
		TEST( "----------------------- Dest. ------------------------");
		delete i;
		delete j;
	}
	{
		TITLE( "\n----------------------- Test 3 -----------------------");
		TEST( "Copy test dog (new)");
		TEST( "----------------------- Const. -----------------------");
		Dog* dog1 = new Dog();
		Dog dog2(*dog1);
		srand(time(0));
		int id = (rand() % 100 + 1);
		TEST( "------------------------ Dog1 ------------------------");
		cout << dog1->getType() << endl;
		dog1->makeSound();
		cout << dog1->getIdea(id) << endl;
		dog1->setIdea("I want to be a cat", id);
		cout << dog1->getIdea(id) << endl;
		TEST( "----------------------- Dest. ------------------------");
		delete dog1;
		TEST( "------------------------ Dog2 ------------------------");
		cout << dog2.getType() << endl;
		dog2.makeSound();
		cout << dog2.getIdea(id) << endl;
		TEST( "----------------------- Dest. ------------------------");
	}
	{
		TITLE( "\n----------------------- Test 4 -----------------------");
		TEST( "Copy test cat (new)");
		TEST( "----------------------- Const. -----------------------");
		Cat* cat1 = new Cat();
		Cat cat2(*cat1);
		srand(time(0));
		int id = (rand() % 100 + 1);
		TEST( "------------------------ Cat1 ------------------------");
		cout << cat1->getType() << endl;
		cat1->makeSound();
		cout << cat1->getIdea(id) << endl;
		cat1->setIdea("I want to be a doggo", id);
		cout << cat1->getIdea(id) << endl;
		TEST( "----------------------- Dest. ------------------------");
		delete cat1;
		TEST( "------------------------ Cat2 ------------------------");
		cout << cat2.getType() << endl;
		cat2.makeSound();
		cout << cat2.getIdea(id) << endl;
		TEST( "----------------------- Dest. ------------------------");
	}
	{
		TITLE( "\n----------------------- Test 5 -----------------------");
		TEST( "getter & setter");
		TEST( "----------------------- Const. -----------------------");
		Cat cat;
		TEST( "------------------------ Test ------------------------");
		for (int i = 1; i <= 10; i++) {
			cout << i << ": " << cat.getIdea(i) << endl;
		}
		TEST( "------------------------------------------------------");
		cat.setIdea("MEOW!!!", 2);
		cat.setIdea("MEEEEEEOOOOOOW!!!", 7);
		for (int i = 1; i <= 10; i++) {
			cout << i << ": " << cat.getIdea(i) << endl;
		}
		TEST( "----------------------- Dest. ------------------------");
	}
	TITLE( "--------------------- End Tests ----------------------");
}