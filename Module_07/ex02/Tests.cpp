/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/30 15:07:43 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Tests.hpp"

void runTests() {
	{
		srand(time(0));
		TITLE( "--------------------- TESTS INT ----------------------");
		TITLE( "----------------------- Test 1 -----------------------");
		TEST( "Basic test w/ size = 0 - OK");
		try {
			Array<int> tab; 
			cout << C_BOL C_BLU "Array size: " C_WHT << tab.size() << endl;
			cout << C_BOL C_BLU "Array content: " C_WHT << endl;
		} catch(exception &e) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n----------------------- Test 2 -----------------------");
		TEST( "Basic test w/ size = 5 - OK");
		try {
			Array<int> tab(5);

			for ( unsigned int i = 0; i < tab.size(); i++ ) {
				tab[i] = rand();
			}

			cout << C_BOL C_BLU "Array size: " C_WHT << tab.size() << endl;
			cout << C_BOL C_BLU "Array content: " C_WHT << endl;
			for ( unsigned int i = 0; i < tab.size(); i++ ) {
				cout << "\t * tab[" << i << "]: " << tab[i] << endl;
			}
		} catch(exception &e) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n----------------------- Test 3 -----------------------");
		TEST( "Bad Index test : value == _size - KO");
		try {
			Array<int> tab(5);

			for ( unsigned int i = 0; i < tab.size(); i++ ) {
				tab[i] = rand();
			}

			cout << C_BOL C_BLU "Array size: " C_WHT << tab.size() << endl;
			cout << C_BOL C_BLU "Array content: " C_WHT << endl;
			for ( unsigned int i = 0; i < tab.size(); i++ ) {
				cout << "\t * tab[" << i << "]: " << tab[i] << endl;
			}
			cout << "\t * tab[5]: " << tab[5] << endl;
		} catch(exception &e) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n----------------------- Test 4 -----------------------");
		TEST( "Bad Index test : value > _size - KO");
		try {
			Array<int> tab(5);

			for ( unsigned int i = 0; i < tab.size(); i++ ) {
				tab[i] = rand();
			}

			cout << C_BOL C_BLU "Array size: " C_WHT << tab.size() << endl;
			cout << C_BOL C_BLU "Array content: " C_WHT << endl;
			for ( unsigned int i = 0; i < tab.size(); i++ ) {
				cout << "\t * tab[" << i << "]: " << tab[i] << endl;
			}
			cout << "\t * tab[42]: " << tab[6] << endl;
		} catch(exception &e) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n----------------------- Test 5 -----------------------");
		TEST( "Bad Index test : value < 0 - KO");
		try {
			Array<int> tab(5);

			for ( unsigned int i = 0; i < tab.size(); i++ ) {
				tab[i] = rand();
			}

			cout << C_BOL C_BLU "Array size: " C_WHT << tab.size() << endl;
			cout << C_BOL C_BLU "Array content: " C_WHT << endl;
			for ( unsigned int i = 0; i < tab.size(); i++ ) {
				cout << "\t * tab[" << i << "]: " << tab[i] << endl;
			}
			cout << "\t * tab[-7]: " << tab[6] << endl;
		} catch(exception &e) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n----------------------- Test 6 -----------------------");
		TEST( "Copy test w/ same size - OK");
		try {
			Array<int> tab(5);

			for ( unsigned int i = 0; i < tab.size(); i++ ) {
				tab[i] = i;
			}

			TEST( "----------------------- Array1 -----------------------");
			cout << C_BOL C_BLU "Array_1 adress: " C_WHT << &tab << endl;
			cout << C_BOL C_BLU "Array_1 size: " C_WHT << tab.size() << endl;
			cout << C_BOL C_BLU "Array_1 content: " C_WHT << endl;
			for ( unsigned int i = 0; i < tab.size(); i++ ) {
				cout << "\t * tab[" << i << "]: " << tab[i] << endl;
			}

			Array<int> tab_copy(5);

			for ( unsigned int i = 0; i < tab_copy.size(); i++ ) {
				tab_copy[i] = 42;
			}

			TEST( "----------------------- Array2 -----------------------");
			cout << C_BOL C_BLU "Array_2 adress: " C_WHT << &tab_copy << endl;
			cout << C_BOL C_BLU "Array_2 size: " C_WHT << tab_copy.size() << endl;
			cout << C_BOL C_BLU "Array_2 content: " C_WHT << endl;
			for ( unsigned int i = 0; i < tab_copy.size(); i++ ) {
				cout << "\t * tab[" << i << "]: " << tab_copy[i] << endl;
			}

			TEST( "************************ Copy ************************");
			tab_copy = tab;

			TEST( "----------------------- Array2 -----------------------");
			cout << C_BOL C_BLU "Array_2 adress: " C_WHT << &tab_copy << endl;
			cout << C_BOL C_BLU "Array_2 size: " C_WHT << tab_copy.size() << endl;
			cout << C_BOL C_BLU "Array_2 content: " C_WHT << endl;
			for ( unsigned int i = 0; i < tab.size(); i++ ) {
				cout << "\t * tab[" << i << "]: " << tab_copy[i] << endl;
			}

			TEST( "----------------------- Array1 -----------------------");
			cout << C_BOL C_BLU "Array_1 adress: " C_WHT << &tab << endl;
			cout << C_BOL C_BLU "Array_1 size: " C_WHT << tab.size() << endl;
			cout << C_BOL C_BLU "Array_1 content: " C_WHT << endl;
			for ( unsigned int i = 0; i < tab.size(); i++ ) {
				cout << "\t * tab[" << i << "]: " << tab[i] << endl;
			}
		} catch(exception &e) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n----------------------- Test 7 -----------------------");
		TEST( "Copy test w/ different size (src bigger) - OK");
		try {
			Array<int> tab(5);

			for ( unsigned int i = 0; i < tab.size(); i++ ) {
				tab[i] = i;
			}

			TEST( "----------------------- Array1 -----------------------");
			cout << C_BOL C_BLU "Array_1 adress: " C_WHT << &tab << endl;
			cout << C_BOL C_BLU "Array_1 size: " C_WHT << tab.size() << endl;
			cout << C_BOL C_BLU "Array_1 content: " C_WHT << endl;
			for ( unsigned int i = 0; i < tab.size(); i++ ) {
				cout << "\t * tab[" << i << "]: " << tab[i] << endl;
			}

			Array<int> tab_copy(3);

			for ( unsigned int i = 0; i < tab_copy.size(); i++ ) {
				tab_copy[i] = 42;
			}

			TEST( "----------------------- Array2 -----------------------");
			cout << C_BOL C_BLU "Array_2 address: " C_WHT << &tab_copy << endl;
			cout << C_BOL C_BLU "Array_2 size: " C_WHT << tab_copy.size() << endl;
			cout << C_BOL C_BLU "Array_2 content: " C_WHT << endl;
			for ( unsigned int i = 0; i < tab_copy.size(); i++ ) {
				cout << "\t * tab[" << i << "]: " << tab_copy[i] << endl;
			}

			TEST( "************************ Copy ************************");
			tab_copy = tab;

			TEST( "----------------------- Array2 -----------------------");
			cout << C_BOL C_BLU "Array_2 address: " C_WHT << &tab_copy << endl;
			cout << C_BOL C_BLU "Array_2 size: " C_WHT << tab_copy.size() << endl;
			cout << C_BOL C_BLU "Array_2 content: " C_WHT << endl;
			for ( unsigned int i = 0; i < tab.size(); i++ ) {
				cout << "\t * tab[" << i << "]: " << tab_copy[i] << endl;
			}
			
			TEST( "----------------------- Array1 -----------------------");
			cout << C_BOL C_BLU "Array_1 adress: " C_WHT << &tab << endl;
			cout << C_BOL C_BLU "Array_1 size: " C_WHT << tab.size() << endl;
			cout << C_BOL C_BLU "Array_1 content: " C_WHT << endl;
			for ( unsigned int i = 0; i < tab.size(); i++ ) {
				cout << "\t * tab[" << i << "]: " << tab[i] << endl;
			}
		} catch(exception &e) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n----------------------- Test 8 -----------------------");
		TEST( "Copy test w/ different size (dest bigger) - OK");
		try {
			Array<int> tab(3);

			for ( unsigned int i = 0; i < tab.size(); i++ ) {
				tab[i] = i;
			}

			TEST( "----------------------- Array1 -----------------------");
			cout << C_BOL C_BLU "Array_1 address: " C_WHT << &tab << endl;
			cout << C_BOL C_BLU "Array_1 size: " C_WHT << tab.size() << endl;
			cout << C_BOL C_BLU "Array_1 content: " C_WHT << endl;
			for ( unsigned int i = 0; i < tab.size(); i++ ) {
				cout << "\t * tab[" << i << "]: " << tab[i] << endl;
			}

			Array<int> tab_copy(5);

			for ( unsigned int i = 0; i < tab_copy.size(); i++ ) {
				tab_copy[i] = 42;
			}

			TEST( "----------------------- Array2 -----------------------");
			cout << C_BOL C_BLU "Array_2 adress: " C_WHT << &tab_copy << endl;
			cout << C_BOL C_BLU "Array_2 size: " C_WHT << tab_copy.size() << endl;
			cout << C_BOL C_BLU "Array_2 content: " C_WHT << endl;
			for ( unsigned int i = 0; i < tab_copy.size(); i++ ) {
				cout << "\t * tab[" << i << "]: " << tab_copy[i] << endl;
			}

			TEST( "************************ Copy ************************");
			tab_copy = tab;

			TEST( "----------------------- Array2 -----------------------");
			cout << C_BOL C_BLU "Array_2 adress: " C_WHT << &tab_copy << endl;
			cout << C_BOL C_BLU "Array_2 size: " C_WHT << tab_copy.size() << endl;
			cout << C_BOL C_BLU "Array_2 content: " C_WHT << endl;
			for ( unsigned int i = 0; i < tab.size(); i++ ) {
				cout << "\t * tab[" << i << "]: " << tab_copy[i] << endl;
			}

			TEST( "----------------------- Array1 -----------------------");
			cout << C_BOL C_BLU "Array_1 address: " C_WHT << &tab << endl;
			cout << C_BOL C_BLU "Array_1 size: " C_WHT << tab.size() << endl;
			cout << C_BOL C_BLU "Array_1 content: " C_WHT << endl;
			for ( unsigned int i = 0; i < tab.size(); i++ ) {
				cout << "\t * tab[" << i << "]: " << tab[i] << endl;
			}
		} catch(exception &e) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n----------------------- Test 9 -----------------------");
		TEST( "Deep copy - OK");
		try {
			Array<int> tab(3);

			for ( unsigned int i = 0; i < tab.size(); i++ ) {
				tab[i] = i;
			}

			TEST( "----------------------- Array1 -----------------------");
			cout << C_BOL C_BLU "Array_1 address: " C_WHT << &tab << endl;
			cout << C_BOL C_BLU "Array_1 size: " C_WHT << tab.size() << endl;
			cout << C_BOL C_BLU "Array_1 content: " C_WHT << endl;
			for ( unsigned int i = 0; i < tab.size(); i++ ) {
				cout << "\t * tab[" << i << "]: " << tab[i] << endl;
			}

			TEST( "************************ Copy ************************");
			Array<int> tab_copy(tab);

			TEST( "----------------------- Array2 -----------------------");
			cout << C_BOL C_BLU "Array_2 adress: " C_WHT << &tab_copy << endl;
			cout << C_BOL C_BLU "Array_2 size: " C_WHT << tab_copy.size() << endl;
			cout << C_BOL C_BLU "Array_2 content: " C_WHT << endl;
			for ( unsigned int i = 0; i < tab.size(); i++ ) {
				cout << "\t * tab[" << i << "]: " << tab_copy[i] << endl;
			}
		} catch(exception &e) {
			cerr << e.what() << endl;
		}
	}
	TITLE( "\n-------------------- OTHER TESTS ---------------------");
	{
		TITLE( "----------------------- Test 10 -----------------------");
		TEST( "Basic test FLOAT - OK");
		try {
			Array<float> tab(5);

			for ( unsigned int i = 0; i < tab.size(); i++ ) {
				tab[i] = rand();
			}

			cout << C_BOL C_BLU "Array size: " C_WHT << tab.size() << endl;
			cout << C_BOL C_BLU "Array content: " C_WHT << endl;
			for ( unsigned int i = 0; i < tab.size(); i++ ) {
				cout << "\t * tab[" << i << "]: " << tab[i] << endl;
			}
		} catch(exception &e) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n---------------------- Test 11 -----------------------");
		TEST( "Basic test DOUBLE - OK");
		try {
			Array<double> tab(5);

			for ( unsigned int i = 0; i < tab.size(); i++ ) {
				tab[i] = rand();
			}

			cout << C_BOL C_BLU "Array size: " C_WHT << tab.size() << endl;
			cout << C_BOL C_BLU "Array content: " C_WHT << endl;
			for ( unsigned int i = 0; i < tab.size(); i++ ) {
				cout << "\t * tab[" << i << "]: " << tab[i] << endl;
			}
			//cout << "\t * tab[5]: " << tab[5] << endl;
		} catch(exception &e) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n---------------------- Test 12 -----------------------");
		TEST( "Basic test CHAR - OK");
		try {
			Array<char> tab(26);

			for ( unsigned int i = 0; i < tab.size(); i++ ) {
				tab[i] = 65 + i;
			}

			cout << C_BOL C_BLU "Array size: " C_WHT << tab.size() << endl;
			cout << C_BOL C_BLU "Array content: " C_WHT << endl;
			for ( unsigned int i = 0; i < tab.size(); i++ ) {
				cout << "\t * tab[" << i << "]: " << tab[i] << endl;
			}
			//cout << "\t * tab[27]: " << tab[27] << endl;
		} catch(exception &e) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n---------------------- Test 13 -----------------------");
		TEST( "Basic test STRING - OK");
		try {
			Array<string> tab(3);

			tab[0] = "Halloween";
			tab[1] = "Pumpkin";
			tab[2] = "Trick or treat";

			cout << C_BOL C_BLU "Array size: " C_WHT << tab.size() << endl;
			cout << C_BOL C_BLU "Array content: " C_WHT << endl;
			for ( unsigned int i = 0; i < tab.size(); i++ ) {
				cout << "\t * tab[" << i << "]: " << tab[i] << endl;
			}
			//cout << "\t * tab[3]: " << tab[3] << endl;
		} catch(exception &e) {
			cerr << e.what() << endl;
		}
	}
	TITLE( "--------------------- End Tests ----------------------");
}