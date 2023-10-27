/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/26 21:14:53 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Dagger.hpp"
#include "Fire.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Tests.hpp"
#include "Thunder.hpp"

void runTests() {
		{
		TITLE( "\n---------------------- Test 1 -----------------------");
		TEST( "Cure class test");
		TEST( "----------------------- Const. -----------------------");
		Cure cure1;
		Cure cure2(cure1);
		Cure cure3 = cure2;
		AMateria* cure4 = new Cure();
		AMateria* clone = cure4->clone();
		TEST( "------------------------ Test ------------------------");
		cout << "cure1_type: " << cure1.getType() << endl;
		cout << "cure2_type: " << cure2.getType() << endl;
		cout << "cure3_type: " << cure3.getType() << endl;
		cout << "cure4_type: " << cure4->getType() << endl;
		cout << "clone_type: " << clone->getType() << endl;
		TEST( "----------------------- Dest. ------------------------");
		delete cure4;
		delete clone;
	}
	{
		TITLE( "\n---------------------- Test 2 -----------------------");
		TEST( "Ice class test");
		TEST( "----------------------- Const. -----------------------");
		Ice ice1;
		Ice ice2(ice1);
		Ice ice3 = ice2;
		AMateria* ice4 = new Ice();
		AMateria* clone = ice4->clone();
		TEST( "------------------------ Test ------------------------");
		cout << "ice1_type: " << ice1.getType() << endl;
		cout << "ice2_type: " << ice2.getType() << endl;
		cout << "ice3_type: " << ice3.getType() << endl;
		cout << "ice4_type: " << ice4->getType() << endl;
		cout << "clone_type: " << clone->getType() << endl;
		TEST( "----------------------- Dest. ------------------------");
		delete ice4;
		delete clone;
	}
	{
		TITLE( "\n---------------------- Test 3 -----------------------");
		TEST( "Character class basic test");
		TEST( "----------------------- Const. -----------------------");
		Character c;
		Character Torgga( "Torgga" );
		Character Yelkas( "Yelkas" );
		TEST( "------------------------ Test ------------------------");
		c.equip( new Ice() );
		Torgga.equip( new Cure() );
		Torgga.equip( new Ice() );
		c.use( 0, Torgga );
		Torgga.use( 0, Yelkas );
		Torgga.use( 1, Yelkas );
		Yelkas.unequip(0);
		TEST( "----------------------- Infos ------------------------");
		c.displayInfos();
		Torgga.displayInfos();
		Yelkas.displayInfos();
		TEST( "----------------------- Dest. ------------------------");
	}
	{
		TITLE( "\n---------------------- Test 4 -----------------------");
		TEST( "Character class *copy* test");
		TEST( "----------------------- Const. -----------------------");
		Character Torgga( "Torgga" );
		Character Nemeia( "Nemeia" );
		TEST( "------------------------ Test ------------------------");
		Torgga.equip( new Cure() );
		Torgga.equip( new Cure() );
		Torgga.equip( new Cure() );
		Nemeia.equip( new Ice() );
		Nemeia.equip( new Ice() );
		TEST( "----------------------- Infos ------------------------");
		Torgga.displayInfos();
		Nemeia.displayInfos();
		TEST( "---------------------- Test copy ----------------------");
		Character Yelkas( Nemeia );
		Yelkas.displayInfos();
		Character Lothric = Yelkas;
		Lothric.displayInfos();
		Nemeia = Torgga;
		Nemeia.displayInfos();
		TEST( "----------------------- Dest. ------------------------");
	}
	{
		TITLE( "\n---------------------- Test 5 -----------------------");
		TEST( "Character class *equip* test");
		TEST( "----------------------- Const. -----------------------");
		Character Torgga( "Torgga" );
		TEST( "------------------------ Test ------------------------");
		Ice* ice1 = nullptr;
		Torgga.equip( ice1 );
		Cure* cure1 = new Cure();
		Torgga.equip( cure1 );
		Fire* ice2 = new Fire();
		Torgga.equip( ice2 );
		Thunder* cure2 = new Thunder();
		Torgga.equip( cure2 );
		Dagger* ice3 = new Dagger();
		Torgga.equip( ice3 );
		ice1 = new Ice();
		Torgga.equip( ice1 );
		TEST( "----------------------- Infos ------------------------");
		Torgga.displayInfos();
		TEST( "----------------------- Dest. ------------------------");
		delete ice1;
	}
	{
		TITLE( "\n---------------------- Test 6 -----------------------");
		TEST( "Character class *unequip* test");
		TEST( "----------------------- Const. -----------------------");
		Character Torgga( "Torgga" );
		Ice* ice1 = new Ice();
		Ice* ice2 = new Ice();
		Cure* cure1 = new Cure();
		Cure* cure2 = new Cure();
		TEST( "----------------------- Equip ------------------------");
		Torgga.equip( ice1 );
		Torgga.equip( ice2 );
		Torgga.equip( cure1 );
		Torgga.equip( cure2 );
		TEST( "----------------------- Infos ------------------------");
		Torgga.displayInfos();
		TEST( "----------------------- Unequip ------------------------");
		Torgga.unequip( 0 );
		Torgga.unequip( 1 );
		Torgga.unequip( 2 );
		Torgga.unequip( 3 );
		Torgga.unequip( 4 );
		TEST( "----------------------- Dest. ------------------------");
	}
	{
		TITLE( "\n---------------------- Test 7 -----------------------");
		TEST( "Character class *use* test");
		TEST( "----------------------- Const. -----------------------");
		Character Torgga( "Torgga" );
		Character Yelkas;
		TEST( "------------------------ Use -------------------------");
		Torgga.use( 0, Yelkas );
		TEST( "----------------------- Equip ------------------------");
		Ice* ice = new Ice();
		Cure* cure = new Cure();
		Torgga.equip( ice );
		Torgga.equip( cure );
		TEST( "----------------------- Infos ------------------------");
		Torgga.displayInfos();
		TEST( "------------------------ Use -------------------------");
		Torgga.use( 0, Yelkas );
		Torgga.use( 1, Yelkas );
		TEST( "----------------------- Unequip ------------------------");
		Torgga.unequip( 0 );
		Torgga.unequip( 1 );
		TEST( "----------------------- Dest. ------------------------");
	}
	{
		TITLE( "\n---------------------- Test 8 -----------------------");
		TEST( "ICharacter class test");
		TEST( "----------------------- Const. -----------------------");
		ICharacter* Torgga = new Character( "Torgga" );
		ICharacter* Yelkas = new Character( "Yelkas" );
		TEST( "----------------------- Equip ------------------------");
		Ice* ice = new Ice();
		Cure* cure = new Cure();
		Torgga->equip( ice );
		Torgga->equip( cure );
		TEST( "------------------------ Use -------------------------");
		Torgga->use( 0, *Yelkas );
		Torgga->use( 1, *Yelkas );
		TEST( "----------------------- Unequip ------------------------");
		Torgga->unequip( 4 );
		Torgga->unequip( 1 );
		TEST( "----------------------- Dest. ------------------------");
		delete Torgga;
		delete Yelkas;
	}
	{
		TITLE( "\n---------------------- Test 9 -----------------------");
		TEST( "MateriaSource class *learn* test");
		TEST( "----------------------- Const. -----------------------");
		IMateriaSource* src = new MateriaSource();
		TEST( "------------------------ Test ------------------------");
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		TEST( "----------------------- Dest. ------------------------");
		delete src;
	}
	{
		TITLE( "\n---------------------- Test 10 -----------------------");
		TEST( "MateriaSource class *create* test");
		TEST( "----------------------- Const. -----------------------");
		IMateriaSource* src = new MateriaSource();
		ICharacter* me = new Character("me");
		TEST( "------------------------ Test ------------------------");
		src->learnMateria(new Ice());
		AMateria* tmp = src->createMateria("ice");
		me->equip(tmp);
		TEST( "----------------------- Dest. ------------------------");
		delete src;
		delete me;
	}
	{
		TITLE( "\n---------------------- Test 11 -----------------------");
		TEST( "MateriaSource class *all* test");
		TEST( "----------------------- Const. -----------------------");
		IMateriaSource* src = new MateriaSource();
		ICharacter* Jack = new Character("Jack");
		ICharacter* Bob = new Character("Bob");
		Ice* ice = new Ice();
		Cure* cure = new Cure();
		Fire* fire = new Fire();
		Thunder* thunder = new Thunder();
		Dagger* dagger = new Dagger();
		AMateria* tmp;
		TEST( "----------------------- Equip ------------------------");
		src->learnMateria( ice );
		src->learnMateria( cure );
		src->learnMateria( fire );
		src->learnMateria( thunder );
		src->learnMateria( dagger );

		tmp = src->createMateria("ice");
		Jack->equip(tmp);
		tmp = src->createMateria("cure");
		Jack->equip(tmp);
		tmp = src->createMateria( "" );
		tmp = src->createMateria("thunder");
		Jack->equip(tmp);
		tmp = src->createMateria("water");
		tmp = src->createMateria("fire");
		Jack->equip(tmp);
		tmp = src->createMateria("dagger");
		Jack->equip(tmp);
		TEST( "------------------------ Use -------------------------");
		Jack->use( 0, *Bob );
		Jack->use( 1, *Bob );
		Jack->use( 2, *Bob );
		Jack->use( 3, *Bob );
		TEST( "---------------------- Unequip -----------------------");
		Jack->unequip( 4 );
		Jack->unequip( 1 );
		Jack->unequip( 3 );
		TEST( "----------------------- Dest. ------------------------");
		delete tmp;
		delete src;
		delete Jack;
		delete Bob;
	}
	{
		TITLE( "\n---------------------- Test 12 -----------------------");
		TEST( "MateriaSource class *all* test");
		TEST( "----------------------- Const. -----------------------");
		IMateriaSource* src = new MateriaSource();
		ICharacter* me = new Character("me");
		TEST( "------------------------ Test ------------------------");
		src->learnMateria(new Ice());
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		src->learnMateria(new Cure());
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		TITLE( "\n------------------------------------------------------");
		me->use(0, *bob);
		me->use(1, *bob);
		TITLE( "------------------------------------------------------");
		TEST( "\n----------------------- Dest. ------------------------");
		delete src;
		delete me;
		delete bob;
	}
	TITLE( "--------------------- End Tests ----------------------");
}