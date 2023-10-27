/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/26 21:06:35 by gwenolalero      ###   ########.fr       */
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

int main() {
	{
		TITLE( "-------------------- Test Subject --------------------");
		TEST( "----------------------- Const. -----------------------");
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		TEST( "------------------------ Test ------------------------");
		me->use(0, *bob);
		me->use(1, *bob);

		TEST( "----------------------- Dest. ------------------------");
		delete bob;
		delete me;
		delete src;
		TITLE( "--------------------- End Test ----------------------");
	}
	if ( EVAL )
		runTests();
	return 0;
}