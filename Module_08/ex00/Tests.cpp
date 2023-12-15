/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/12/01 12:12:59 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "Tests.hpp"

// No Stack nor Queue tests because values are not accessible
void runTests() {
	{
		TITLE( "-------------------- VECTOR tests --------------------");
		TITLE( "----------------------- Test 1 -----------------------");
		TEST( "Basic test : Found - OK");
		try {
			vector<int> v; 
			int valToFind = 78;

			v.push_back(63);
			v.push_back(-75);
			v.push_back(987);
			v.push_back(-89);
			v.push_back(78);

			cout << C_BOL C_BLU "Value to find: " C_WHT << valToFind << endl;
			cout << C_BOL C_BLU "vector size: " C_WHT << v.size() << endl;
			cout << C_BOL C_BLU "vector content: " C_WHT << endl;
			for ( unsigned int i = 0; i < v.size(); i++ ) {
				cout << "\t * v[" << i << "]: " << v[i] << endl;
			}

			::easyfind(v, valToFind);
		} catch(exception &e) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "----------------------- Test 2 -----------------------");
		TEST( "Basic test : Not found - KO");
		try {
			vector<int> v; 
			int valToFind = 12;

			v.push_back(63);
			v.push_back(-75);
			v.push_back(987);
			v.push_back(-89);
			v.push_back(78);

			cout << C_BOL C_BLU "Value to find: " C_WHT << valToFind << endl;
			cout << C_BOL C_BLU "vector size: " C_WHT << v.size() << endl;
			cout << C_BOL C_BLU "vector content: " C_WHT << endl;
			for ( unsigned int i = 0; i < v.size(); i++ ) {
				cout << "\t * v[" << i << "]: " << v[i] << endl;
			}

			::easyfind(v, valToFind);
		} catch(exception &e) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n-------------------- DEQUE tests ---------------------");
		TITLE( "----------------------- Test 3 -----------------------");
		TEST( "Basic test : Found - OK");
		try {
			deque<int> d;

			d.push_front(63);
			d.push_front(-75);
			d.push_front(987);
			d.push_front(76);
			d.push_front(42);
			d.push_front(24);

			int valToFind = 42;

			cout << C_BOL C_BLU "Value to find: " C_WHT << valToFind << endl;
			cout << C_BOL C_BLU "Deque size: " C_WHT << d.size() << endl;
			cout << C_BOL C_BLU "Deque content: " C_WHT << endl;
			for ( unsigned int i = 0; i < d.size(); i++ ) {
				cout << "\t * d[" << i << "]: " << d[i] << endl;
			}

			::easyfind(d, valToFind);
		} catch(exception &e) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "----------------------- Test 4 -----------------------");
		TEST( "Basic test : Not found - KO");
		try {
			deque<int> d;

			d.push_front(63);
			d.push_front(-75);
			d.push_front(987);
			d.push_front(76);

			int valToFind = -9;

			cout << C_BOL C_BLU "Value to find: " C_WHT << valToFind << endl;
			cout << C_BOL C_BLU "Deque size: " C_WHT << d.size() << endl;
			cout << C_BOL C_BLU "Deque content: " C_WHT << endl;
			for ( unsigned int i = 0; i < d.size(); i++ ) {
				cout << "\t * d[" << i << "]: " << d[i] << endl;
			}

			::easyfind(d, valToFind);
		} catch(exception &e) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "----------------------- Test 5 -----------------------");
		TEST( "Container empty - KO");
		try {
			deque<int> d;

			int valToFind = -9;

			cout << C_BOL C_BLU "Value to find: " C_WHT << valToFind << endl;
			cout << C_BOL C_BLU "Deque size: " C_WHT << d.size() << endl;
			cout << C_BOL C_BLU "Deque content: " C_WHT << endl;
			for ( unsigned int i = 0; i < d.size(); i++ ) {
				cout << "\t * d[" << i << "]: " << d[i] << endl;
			}

			::easyfind(d, valToFind);
		} catch(exception &e) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n-------------------- ARRAY tests ----------------------");
		TITLE( "----------------------- Test 6 -----------------------");
		TEST( "Basic test : Found - OK");
		try {
			array<int, 5> a = { 43, 65, 4, 786, 45 }; 
			int valToFind = 4;

			cout << C_BOL C_BLU "Value to find: " C_WHT << valToFind << endl;
			cout << C_BOL C_BLU "Cont. size: " C_WHT << a.size() << endl;
			cout << C_BOL C_BLU "Cont. content: " C_WHT << endl;
			for ( unsigned int i = 0; i < a.size(); i++ ) {
				cout << "\t * a[" << i << "]: " << a[i] << endl;
			}

			::easyfind(a, valToFind);
		} catch(exception &e) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "----------------------- Test 7 -----------------------");
		TEST( "Basic test : Not found - KO");
		try {
			array<int, 5> a = { 43, 65, 4, 786, 45}; 
			int valToFind = 42;
			
			cout << C_BOL C_BLU "Value to find: " C_WHT << valToFind << endl;
			cout << C_BOL C_BLU "Cont. size: " C_WHT << a.size() << endl;
			cout << C_BOL C_BLU "Cont. content: " C_WHT << endl;
			for ( unsigned int i = 0; i < a.size(); i++ ) {
				cout << "\t * a[" << i << "]: " << a[i] << endl;
			}

			::easyfind(a, valToFind);
		} catch(exception &e) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n-------------------- LIST tests -----------------------");
		TITLE( "----------------------- Test 8 -----------------------");
		TEST( "Basic test : Found - OK");
		try {
			list<int> l; 
			int valToFind = 4;

			l.push_back(6);
			l.push_back(-5);
			l.push_back(7);
			l.push_back(-8);
			l.push_back(4);

			cout << C_BOL C_BLU "Value to find: " C_WHT << valToFind << endl;
			cout << C_BOL C_BLU "Cont. size: " C_WHT << l.size() << endl;
			cout << C_BOL C_BLU "Cont. content: " C_WHT << endl;
			int i = 0;
			for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
				cout << "\t * l[" << i++ << "]: " << *it << endl;
    		}

			::easyfind(l, valToFind);
		} catch(exception &e) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "----------------------- Test 9 -----------------------");
		TEST( "Basic test : Not found - KO");
		try {
			list<int> l; 
			int valToFind = 42;
			
			l.push_back(69);
			l.push_back(-75);
			l.push_back(73);
			l.push_back(89);
			l.push_back(-76);

			cout << C_BOL C_BLU "Value to find: " C_WHT << valToFind << endl;
			cout << C_BOL C_BLU "Cont. size: " C_WHT << l.size() << endl;
			cout << C_BOL C_BLU "Cont. content: " C_WHT << endl;
			int i = 0;
			for(list<int>::iterator it = l.begin(); it != l.end(); ++it) {
				cout << "\t * l[" << i++ << "]: " << *it << endl;
			}

			::easyfind(l, valToFind);
		} catch(exception &e) {
			cerr << e.what() << endl;
		}
	}
	TITLE( "\n--------------------- End Tests ----------------------");
}