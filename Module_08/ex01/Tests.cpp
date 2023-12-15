/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/12/01 16:00:41 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "Tests.hpp"

void runTests() {
		{
		TITLE( "\n----------------------- Test 1 -----------------------");
		TEST( "Basic class test - OK");
		TEST( "------------------------------------------------------");
		try {
			Span sp1 = Span( 1 );
			Span sp2 = Span( sp1 );
			Span sp3 = Span( 1 );

			sp1.addNumber( 42 );
			sp1.addNumber( 42 );
			sp3 = sp2;

			cout << "sp1: " << sp1 << endl;
			cout << "sp2: " << sp2 << endl;
			cout << "sp3: " << sp3 << endl;
		} catch(exception &e) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n----------------------- Test 2 -----------------------");
		TEST( "addNumber() test w/ size 5 - OK");
		TEST( "------------------------------------------------------");
		try {
			Span sp = Span( 5 );

			srand(time(0));
			for ( int i = 0; i < sp.getMaxSize(); i++ ) {
				sp.addNumber( i + rand() % 100 );
			}

			cout << sp << endl;
			cout << sp.shortestSpan() << endl;
			cout << sp.longestSpan() << endl;
		} catch(exception &e) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n----------------------- Test 3 -----------------------");
		TEST( "addNumber() test w/ overload - KO");
		TEST( "------------------------------------------------------");
		try {
			Span sp = Span( 5 );

			for ( int i = 0; i < sp.getMaxSize(); i++ ) {
				sp.addNumber( i + rand() % 100 );
			}

			cout << sp << endl;
			cout << "...Try to add another number..." << endl;
			sp.addNumber( 9 );
		} catch(exception &e) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n----------------------- Test 4 -----------------------");
		TEST( "addNumber() w/ size 1,000 - OK");
		TEST( "------------------------------------------------------");
		try {
			Span sp = Span( 1000 );

			for ( int i = 0; i < sp.getMaxSize(); i++ ) {
				sp.addNumber( rand() );
			}
			//cout << sp << endl;

			cout << sp.shortestSpan() << endl;
			cout << sp.longestSpan() << endl;
		} catch(exception &e) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n----------------------- Test 5 -----------------------");
		TEST( "Too small container exception - KO");
		TEST( "------------------------------------------------------");
		try {
			Span sp = Span( 1 );

			sp.addNumber( 42 );
			cout << sp << endl;

			cout << sp.shortestSpan() << endl;
			cout << sp.longestSpan() << endl;
		} catch(exception &e) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n----------------------- Test 6 -----------------------");
		TEST( "addNumber() w/ size 10,000 (basic filling) - OK");
		TEST( "------------------------------------------------------");
		try {
			Span sp = Span( 10000 );

			for ( int i = 0; i < sp.getMaxSize(); i++ ) {
				sp.addNumber( rand() );
			}
			//cout << sp << endl;

			cout << sp.shortestSpan() << endl;
			cout << sp.longestSpan() << endl;
		} catch(exception &e) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n----------------------- Test 7 -----------------------");
		TEST( "addNumber() w/ size 10,000 (range of iterators) - OK");
		TEST( "------------------------------------------------------");
		try {
			Span sp = Span( 10000 );

			sp.addNumber();

			cout << sp.shortestSpan() << endl;
			cout << sp.longestSpan() << endl;
		} catch(exception &e) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n----------------------- Test 8 -----------------------");
		TEST( "addNumber() w/ size 500,000 (range of iterators) - OK");
		TEST( "------------------------------------------------------");
		try {
			Span sp = Span( 500000 );

			sp.addNumber();

			cout << sp.shortestSpan() << endl;
			cout << sp.longestSpan() << endl;
		} catch(exception &e) {
			cerr << e.what() << endl;
		}
	}
		{
		TITLE( "\n----------------------- Test 9 -----------------------");
		TEST( "addNumber() size error (range of iterators) - KO");
		TEST( "------------------------------------------------------");
		try {
			Span sp = Span( 500000 );

			sp.addNumber();
			sp.addNumber();

			cout << sp.shortestSpan() << endl;
			cout << sp.longestSpan() << endl;
		} catch(exception &e) {
			cerr << e.what() << endl;
		}
	}
	TITLE( "\n--------------------- End Tests ----------------------");
}