/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/19 18:27:25 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void runTests() {
	{
		TEST( "----------------------- Test 1 -----------------------");
		TYPE( "Basic constructors and destructors test" );
		TYPE( "----------------------- Const. -----------------------");
		ClapTrap pj("Torgga");
		ScavTrap robot("C3PO");
		FragTrap frag("Boomer");

		TYPE( "----------------------- Stats ------------------------" );
		cout << "*** ClapTrap ***" << endl;
		cout << "HP: " << pj.getHP() << endl;
		cout << "Energy: " << pj.getEnergy() << endl;
		cout << "Atk Damage: " << pj.getAtkDamage() << endl;
		cout << "*** ScavTrap ***" << endl;
		cout << "HP: " << robot.getHP() << endl;
		cout << "Energy: " << robot.getEnergy() << endl;
		cout << "Atk Damage: " << robot.getAtkDamage() << endl;
		cout << "*** FragTrap ***" << endl;
		cout << "HP: " << frag.getHP() << endl;
		cout << "Energy: " << frag.getEnergy() << endl;
		cout << "Atk Damage: " << frag.getAtkDamage() << endl;
		
		TYPE( "----------------------- Test -------------------------");
		pj.attack("C3PO");
		robot.takeDamage(5);
		robot.attack("Boomer");
		robot.takeDamage(20);
		frag.attack("Torgga");
		robot.attack("Torgga");
		robot.takeDamage(30);
		TYPE( "----------------------- Dest. ------------------------");
	}
	{
		TEST( "\n----------------------- Test 2 -----------------------");
		TYPE( "High fives request" );
		TYPE( "----------------------- Const. -----------------------");
		ClapTrap pj("Torgga");
		ScavTrap robot("C3PO");
		FragTrap frag("Boomer");

		TYPE( "----------------------- Test -------------------------");
		pj.attack("C3PO");
		frag.highFivesGuys();
		robot.takeDamage(7);
		robot.beRepaired(5);
		robot.guardGate();
		robot.attack("Torgga");
		pj.attack("C3PO");
		frag.highFivesGuys();
		robot.takeDamage(4);
		robot.attack("Torgga");
		frag.highFivesGuys();
		robot.beRepaired(7);
		robot.guardGate();
		robot.attack("Torgga");
		frag.highFivesGuys();
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
		FragTrap frag("Boomer");

		TYPE( "----------------------- Test -------------------------");
		pj1.attack("Aleksander");
		pj2.attack("Aleksander");
		robot.takeDamage(15);
		robot.takeDamage(15);
		frag.attack("Yelkas");
		pj1.takeDamage(30);
		TYPE( "----------------------- Dest. ------------------------");
	}
	TEST( "--------------------- End Tests ----------------------");
}