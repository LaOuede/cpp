/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/10 08:17:45 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

# define C_WHT "\e[0m"
# define C_BOL "\e[1m"
# define C_GRN "\e[32m"

void tests() {
	cout << C_BOL << C_GRN << "\n\n------------TESTS-------------" << C_WHT << endl;
	// Test Weapon Class
	cout << C_BOL << "*** Initialization weapons ***" << C_WHT << endl;
	Weapon weaponTorgga("Sword of fire and ice");
	cout << "Torgga : Weapon's name = " << weaponTorgga.getType() << endl;
	weaponTorgga.setType("Soulless Scimitar");
	cout << "Torgga : Weapon's name = " << weaponTorgga.getType() << endl;

	Weapon weaponIzek("Eternal Damnation");
	cout << "\nIzek : Weapon's name = " << weaponIzek.getType() << endl;
	weaponIzek.setType("Stonebreaker");
	cout << "Izek : Weapon's name = " << weaponIzek.getType() << endl;

	// Test HumanA Class
	cout << C_BOL << "\n******* Human A class ********" << C_WHT << endl;
	HumanA torgga("Torgga", weaponTorgga);
	torgga.attack();
	weaponTorgga.setType("Skeletal Longblade");
	torgga.attack();

	// Test HumanB Class
	cout << C_BOL << "\n******* Human B class ********" << C_WHT << endl;
	HumanB izek("Izek");
	izek.attack();
	izek.setWeapon(weaponIzek);
	izek.attack();
	weaponIzek.setType("Widowmaker");
	izek.attack();
}