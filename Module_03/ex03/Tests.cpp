/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/19 18:35:27 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

void runTests() {
	{
		TEST( "----------------------- Test 1 -----------------------");
		TYPE( "Basic constructors and destructors test" );
		TYPE( "----------------------- Const. -----------------------");
		ClapTrap pj("Torgga");
		ScavTrap robot("C3PO");
		FragTrap frag("Boomer");
		DiamondTrap diam1("Frankenstein");
		DiamondTrap diam2;

		TYPE( "----------------------- Stats ------------------------" );
		cout << "*** ScavTrap ***" << endl;
		cout << "HP: " << robot.getHP() << endl;
		cout << "HEnergy: " << robot.getEnergy() << endl;
		cout << "Atk Damage: " << robot.getAtkDamage() << endl;
		cout << "*** FragTrap ***" << endl;
		cout << "HP: " << frag.getHP() << endl;
		cout << "HEnergy: " << frag.getEnergy() << endl;
		cout << "Atk Damage: " << frag.getAtkDamage() << endl;
		cout << "*** DiamondTrap 1 ***" << endl;
		cout << "HP: " << diam1.getHP() << endl;
		cout << "HEnergy: " << diam1.getEnergy() << endl;
		cout << "Atk Damage: " << diam1.getAtkDamage() << endl;
		cout << "*** DiamondTrap 2 ***" << endl;
		cout << "HP: " << diam2.getHP() << endl;
		cout << "HEnergy: " << diam2.getEnergy() << endl;
		cout << "Atk Damage: " << diam2.getAtkDamage() << endl;

		TYPE( "--------------------- Who am I? ----------------------" );
		diam1.whoAmI();
		diam2.whoAmI();
		TYPE( "----------------------- Dest. ------------------------");
	}
	{
		TEST( "\n----------------------- Test 2 -----------------------");
		TYPE( "One character runs out of energy (Attacking)" );
		TYPE( "----------------------- Const. -----------------------");
		DiamondTrap pj("Birzim");

		TYPE( "----------------------- Test -------------------------");
		do {
			pj.attack("a stone Golem");
		} while ( pj.hasEnergy() );
		pj.attack("a stone Golem");
		TYPE( "----------------------- Dest. ------------------------");
	}
	{
		TEST( "\n----------------------- Test 3 -----------------------");
		TYPE( "One character dies" );
		TYPE( "----------------------- Const. -----------------------");
		DiamondTrap diam1("Riu");
		DiamondTrap diam2("Ken");

		TYPE( "--------------------- Who am I? ----------------------" );
		diam1.whoAmI();
		diam2.whoAmI();
		TYPE( "----------------------- Test -------------------------");
		diam1.attack("Ken");
		diam2.takeDamage(30);
		diam1.attack("Ken");
		diam2.takeDamage(30);
		diam1.attack("Ken");
		diam2.takeDamage(30);
		diam2.attack("Riu");
		diam1.takeDamage(30);
		diam1.attack("Ken");
		diam2.takeDamage(30);
		diam2.attack("Riu");
		TYPE( "----------------------- Dest. ------------------------");
	}
	TEST( "--------------------- End Tests ----------------------");
}