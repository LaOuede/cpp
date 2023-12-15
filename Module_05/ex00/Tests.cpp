/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/02 21:06:32 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Tests.hpp"

void runTests() {
	{
		TITLE( "---------------------- Test 1 -----------------------");
		TEST( "Grade incrementation / Default const. - OK");
		try {
			TEST( "----------------------- Const. -----------------------");
			Bureaucrat bur;
			TEST( "------------------------ Test ------------------------");
			cout << bur;
			bur.incrementGrade();
			cout << bur;
			TEST( "----------------------- Dest. ------------------------");
		} catch ( exception & e ) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n\n---------------------- Test 2 -----------------------");
		try {
			TEST( "Grade incrementation / Param. const. - OK");
			TEST( "----------------------- Const. -----------------------");
			Bureaucrat bur( "IRobot", 74 );
			TEST( "------------------------ Test ------------------------");
			cout << bur;
			bur.incrementGrade();
			cout << bur;
			TEST( "----------------------- Dest. ------------------------");
		} catch ( exception & e ) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n\n---------------------- Test 3 -----------------------");
		TEST( "Grade incrementation / Param. const. - KO");
		try {
			TEST( "----------------------- Const. -----------------------");
			Bureaucrat bur( "Jake", 1 );
			TEST( "------------------------ Test ------------------------");
			cout << bur;
			bur.incrementGrade();
			cout << bur;
		} catch ( exception & e ) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n\n---------------------- Test 4 -----------------------");
		TEST( "Grade decrementation / Default const. - KO");
		try {
			TEST( "----------------------- Const. -----------------------");
			Bureaucrat bur;
			TEST( "------------------------ Test ------------------------");
			cout << bur;
			bur.decrementGrade();
			cout << bur;
		} catch ( exception & e ) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n\n---------------------- Test 5 -----------------------");
		TEST( "Grade decrementation / Param const. - OK");
		try {
			TEST( "----------------------- Const. -----------------------");
			Bureaucrat bur( "Joe", 42 );
			TEST( "------------------------ Test ------------------------");
			cout << bur;
			bur.decrementGrade();
			cout << bur;
			TEST( "----------------------- Dest. ------------------------");
		} catch ( exception & e ) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n\n---------------------- Test 6 -----------------------");
		TEST( "Grade decrementation / Param const. - KO");
		try {
			TEST( "----------------------- Const. -----------------------");
			Bureaucrat bur( "Joe", 150 );
			TEST( "------------------------ Test ------------------------");
			cout << bur;
			bur.decrementGrade();
			cout << bur;
		} catch ( exception & e ) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n\n---------------------- Test 7 -----------------------");
		TEST( "Bad instanciation - grade too low");
		try {
			Bureaucrat bur( "Luis", 199 );
			cout << bur;
		} catch ( exception & e ) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n\n---------------------- Test 8 -----------------------");
		TEST( "Bad instanciation - grade too high");
		try {
			Bureaucrat bur( "Luis", -7 );
			cout << bur;
		} catch ( exception & e ) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n\n---------------------- Test 9 -----------------------");
		TEST( "Basic class test");
		TEST( "----------------------- Const. -----------------------");
		Bureaucrat	bur;
		Bureaucrat	bur1( "R1", 7 );
		Bureaucrat	bur2( bur1 );
		Bureaucrat	bur3 = bur2;
		TEST( "----------------------- Infos ------------------------");
		cout << "bur:  " << bur;
		cout << "bur1: " << bur1;
		cout << "bur2: " << bur2;
		cout << "bur3: " << bur3;
		TEST( "----------------------- Dest. ------------------------");
	}
	{
		TITLE( "\n\n---------------------- Test 10 -----------------------");
		TEST( "Deep copy test");
		TEST( "----------------------- Const. -----------------------");
		Bureaucrat *bur1 = new Bureaucrat("Joe", 17);
		Bureaucrat *bur2 = new Bureaucrat(*bur1);
		TEST( "------------------------ Test ------------------------");
		cout << "Original: " << *bur1;
		cout << "Copy: " << *bur2;
		TEST( "---------------------- dec. bur1 ---------------------");
		try {
			bur1->decrementGrade();
			cout << "Original: " << *bur1;
			cout << "Copy: " << *bur2;
		} catch ( exception & e ) {
			cerr << e.what() << endl;
		}
		TEST( "---------------------- inc. bur2 ---------------------");
		try {
			bur2->incrementGrade();
			cout << "Original: " << *bur1;
			cout << "Copy: " << *bur2;
		} catch ( exception & e ) {
			cerr << e.what() << endl;
		}
		TEST( "----------------------- Dest. ------------------------");
		delete bur1;
		delete bur2;
	}
	TITLE( "\n--------------------- End Tests ----------------------");
}