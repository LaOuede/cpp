/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/30 12:07:05 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include "Tests.hpp"

// Class Test
Test::Test( string order, uint mana, string favWeapon ) :
	_order( order ), _mana( mana ), _favWeapon( favWeapon ) {};

Test::~Test() {};

string const &Test::getOrder() const { return this->_order; }
uint const &Test::getMana() const { return this->_mana; }
string const &Test::getfavWeapon() const { return this->_favWeapon; }

ostream &operator<<( ostream &o, Test const &rhs ) {
	cout << "Order: " << rhs.getOrder() << endl;
	cout << "Mana: " << rhs.getMana() << endl;
	cout << "Weapon: " << rhs.getfavWeapon() << endl;
	return o;
}
// Class Test - END

void runTests() {
	{
		TITLE( "----------------------- Test 1 -----------------------");
		TEST( "Increment int tab test - OK");
		int tab[5] = { 75, 31, -87, 14, 90 };
		size_t sizeTab = 5;
		TEST( "------------------------ Test ------------------------");
		cout << "--- print. ---" << endl;
		::iter( tab, sizeTab , &print );
		cout << "---- inc. ----" << endl;
		::iter( tab, sizeTab , &increment );
		::iter( tab, sizeTab , &print );
		cout << "---- dec. ----" << endl;
		::iter( tab, sizeTab , &decrement );
		::iter( tab, sizeTab , &print );
	}
	{
		TITLE( "----------------------- Test 2 -----------------------");
		TEST( "Increment double tab test - OK");
		double tab[5] = { 7.87, 3.81, -8.97, 14.65, 90.76 };
		size_t sizeTab = 5;
		TEST( "------------------------ Test ------------------------");
		cout << "--- print. ---" << endl;
		::iter( tab, sizeTab , &print );
		cout << "---- inc. ----" << endl;
		::iter( tab, sizeTab , &increment );
		::iter( tab, sizeTab , &print );
		cout << "---- dec. ----" << endl;
		::iter( tab, sizeTab , &decrement );
		::iter( tab, sizeTab , &print );
	}
	{
		TITLE( "----------------------- Test 3 -----------------------");
		TEST( "Increment char tab test - OK");
		char tab[5] = { 'A', 'B', 'C', 'D', 'E' };
		size_t sizeTab = 5;
		TEST( "------------------------ Test ------------------------");
		cout << "--- print. ---" << endl;
		::iter( tab, sizeTab , &print );
		cout << "---- inc. ----" << endl;
		::iter( tab, sizeTab , &increment );
		::iter( tab, sizeTab , &print );
		cout << "---- dec. ----" << endl;
		::iter( tab, sizeTab , &decrement );
		::iter( tab, sizeTab , &print );
	}
	{
		TITLE( "----------------------- Test 4 -----------------------");
		TEST( "Increment float tab test - OK");
		float tab[5] = { 43.09, 13.345, 65.8723, 72.00, -76.234 };
		size_t sizeTab = 5;
		TEST( "------------------------ Test ------------------------");
		cout << "--- print. ---" << endl;
		::iter( tab, sizeTab , &print );
		cout << "---- inc. ----" << endl;
		::iter( tab, sizeTab , &increment );
		::iter( tab, sizeTab , &print );
		cout << "---- dec. ----" << endl;
		::iter( tab, sizeTab , &decrement );
		::iter( tab, sizeTab , &print );
	}
	{
		TITLE( "----------------------- Test 5 -----------------------");
		TEST( "Print string tab test - OK");
		string tab[5] = { "Cleric", "Vampire", "Warrior", "Pirates", "Dinos" };
		size_t sizeTab = 5;
		TEST( "------------------------ Test ------------------------");
		cout << "--- print. ---" << endl;
		::iter( tab, sizeTab , &print );
	}
	{
		TITLE( "----------------------- Test 6 -----------------------");
		TEST( "Class Test - OK");
		Test tab[3] = { Test("Cleric", 6, "Flail"), Test("Vampire", 45, "Teeth"), Test("Pirate", 2, "Canon")};
		size_t sizeTab = 3;
		TEST( "------------------------ Test ------------------------");
		cout << "--- print. ---" << endl;
		::iter( tab, sizeTab , &print );
	}
	TITLE( "--------------------- End Tests ----------------------");
}