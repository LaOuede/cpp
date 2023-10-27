/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/19 18:18:00 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void runTests() {
	{
		TEST( "----------------------- Test 1 -----------------------");
		TYPE( "Basic constructors and destructors test" );
		TYPE( "----------------------- Const. -----------------------");
		ClapTrap pj1("Torgga");
		ClapTrap pj2;
		ClapTrap pj3(pj1);
		ScavTrap robot("C3PO");

		TYPE( "----------------------- Stats ------------------------" );
		cout << "*** ClapTrap ***" << endl;
		cout << "HP: " << pj1.getHP() << endl;
		cout << "Energy: " << pj1.getEnergy() << endl;
		cout << "Atk Damage: " << pj1.getAtkDamage() << endl;
		cout << "*** ScavTrap ***" << endl;
		cout << "HP: " << robot.getHP() << endl;
		cout << "Energy: " << robot.getEnergy() << endl;
		cout << "Atk Damage: " << robot.getAtkDamage() << endl;

		TYPE( "----------------------- Test -------------------------");
		pj1.attack("C3PO");
		pj3.attack("C3PO");
		robot.takeDamage(4);
		robot.attack("Torgga");
		pj1.takeDamage(20);
		TYPE( "----------------------- Dest. ------------------------");
	}
	{
		TEST( "\n----------------------- Test 2 -----------------------");
		TYPE( "Guardian mode test" );
		TYPE( "----------------------- Const. -----------------------");
		ClapTrap pj("Torgga");
		ScavTrap robot("C3PO");

		TYPE( "----------------------- Test -------------------------");
		pj.attack("C3PO");
		robot.takeDamage(7);
		robot.beRepaired(5);
		robot.guardGate();
		robot.attack("Torgga");
		pj.attack("C3PO");
		robot.takeDamage(4);
		robot.attack("Torgga");
		robot.beRepaired(7);
		robot.guardGate();
		robot.attack("Torgga");
		pj.takeDamage(20);
		pj.beRepaired(5);
		TYPE( "----------------------- Dest. ------------------------");
	}
	{
		TEST( "\n----------------------- Test 3 -----------------------");
		TYPE( "One character dies" );
		TYPE( "----------------------- Const. -----------------------");
		ClapTrap pj1("Yelkas");
		ClapTrap pj2;
		ScavTrap robot("Aleksander");

		TYPE( "----------------------- Test -------------------------");
		do {
			pj1.attack("Aleksander");
			pj2.attack("Aleksander");
			robot.takeDamage(15);
			robot.takeDamage(15);
		} while (robot.getHP() > 0);
		TYPE( "----------------------- Dest. ------------------------");
	}
	TEST( "--------------------- End Tests ----------------------");
}