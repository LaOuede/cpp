/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/19 18:09:38 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"
#include "ClapTrap.hpp"

void runTests() {
	{
		TEST( "----------------------- Test 1 -----------------------");
		TYPE( "Basic test" );
		TYPE( "----------------------- Const. -----------------------");
		ClapTrap pj1("Yelkas");
		ClapTrap pj2("Torgga");
		
		pj1.attack("Torgga");
		pj1.takeDamage(7);
		pj1.beRepaired(5);
		TYPE( "----------------------- Dest. ------------------------");
	}
	{
		TEST( "\n----------------------- Test 2 -----------------------");
		TYPE( "One character dies" );
		TYPE( "----------------------- Const. -----------------------");
		ClapTrap pj1("Yelkas");
		ClapTrap pj2;

		TYPE( "----------------------- Test -------------------------");
		pj1.attack(pj2.getName());
		pj2.takeDamage(7);
		pj2.attack("Yelkas");
		pj1.takeDamage(4);
		pj2.attack("Yelkas");
		pj1.takeDamage(4);
		pj1.beRepaired(5);
		pj1.attack(pj2.getName());
		pj2.takeDamage(7);
		pj2.beRepaired(6);
		TYPE( "----------------------- Dest. ------------------------");
	}
	{
		TEST( "\n----------------------- Test 3 -----------------------");
		TYPE( "One character runs out of energy (Attacking)" );
		TYPE( "----------------------- Const. -----------------------");
		ClapTrap pj("Birzim");

		TYPE( "----------------------- Test -------------------------");
		do {
			pj.attack("a stone Golem");
		} while ( pj.hasEnergy() );
		pj.attack("a stone Golem");
		TYPE( "----------------------- Dest. ------------------------");
	}
	{
		TEST( "\n----------------------- Test 4 -----------------------");
		TYPE( "One character runs out of energy (Healing)" );
		TYPE( "----------------------- Const. -----------------------");
		ClapTrap pj1("Aleksander");
		ClapTrap pj2;
		ClapTrap pj3(pj1);
		ClapTrap pj4("Nemeia");

		TYPE( "----------------------- Test -------------------------");
		pj2.attack(pj1.getName());
		pj3.takeDamage(7);
		pj3.beRepaired(3);
		pj1.attack(pj1.getName());
		pj3.takeDamage(2);
		pj3.beRepaired(6);
		pj4.attack(pj1.getName());
		pj3.takeDamage(2);
		pj3.beRepaired(6);
		pj2.attack(pj1.getName());
		pj3.takeDamage(7);
		pj3.beRepaired(3);
		pj1.attack(pj1.getName());
		pj3.takeDamage(2);
		pj3.beRepaired(6);
		pj4.attack(pj1.getName());
		pj3.takeDamage(2);
		pj3.beRepaired(6);
		pj2.attack(pj1.getName());
		pj3.takeDamage(2);
		pj3.beRepaired(6);
		pj2.attack(pj1.getName());
		pj3.takeDamage(7);
		pj3.beRepaired(3);
		pj4.attack(pj1.getName());
		pj3.takeDamage(2);
		pj3.beRepaired(6);
		pj4.attack(pj1.getName());
		pj3.takeDamage(2);
		pj3.beRepaired(6);
		pj4.attack(pj1.getName());
		pj3.takeDamage(2);
		pj3.beRepaired(6);
		TYPE( "----------------------- Dest. ------------------------");
	}
	TEST( "--------------------- End Tests ----------------------");
}