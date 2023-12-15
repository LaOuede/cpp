/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/03 12:35:38 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Tests.hpp"

void runTests() {
	{
		TITLE( "---------------------- Test 1 -----------------------");
		TEST( "signForm - OK");
		TEST( "------------------------------------------------------");
		try {
			Bureaucrat bur( "Stew", 45 );
			Form f( "R2D2", 90, 90 );
			cout << "bur: " << endl << bur;
			cout << "f: " << endl << f;
			bur.signForm( f );
		} catch( exception &e ) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n---------------------- Test 2 -----------------------");
		TEST( "signForm / grade to low - KO");
		TEST( "------------------------------------------------------");
		try {
			Bureaucrat bur( "Stew", 45 );
			Form f( "R2D2", 24, 24 );
			cout << "bur: " << endl << bur;
			cout << "f: " << endl << f;
			bur.signForm( f );
		} catch( exception &e ) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n---------------------- Test 3 -----------------------");
		TEST( "signForm / bad instanciation - KO");
		TEST( "------------------------------------------------------");
		try {
			Bureaucrat bur( "Stew", -8 );
			Form f( "R2D2", 24, 24 );
			cout << "bur: " << endl << bur;
			cout << "f: " << endl << f;
			bur.signForm( f );
		} catch( exception &e ) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n---------------------- Test 4 -----------------------");
		TEST( "signForm / bad instanciation - KO");
		TEST( "------------------------------------------------------");
		try {
			Bureaucrat bur( "Stew", 154 );
			Form f( "R2D2", 24, 24 );
			cout << "bur: " << endl << bur;
			cout << "f: " << endl << f;
			bur.signForm( f );
		} catch( exception &e ) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n---------------------- Test 5 -----------------------");
		TEST( "beSigned + signForm - OK");
		TEST( "------------------------------------------------------");
		try {
			Bureaucrat bur( "Stew", 1);
			Form f( "R2D2", 24, 24 );
			cout << "bur: " << endl << bur;
			cout << "f: " << endl << f;
			bur.signForm( f );
			cout << "f: " << endl << f;
		} catch( exception &e ) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n---------------------- Test 6 -----------------------");
		TEST( "beSigned + signForm / grade to low - KO");
		TEST( "------------------------------------------------------");
		try {
			Bureaucrat bur( "Stew", 56);
			Form f( "R2D2", 24, 24 );
			cout << "bur: " << endl << bur;
			cout << "f: " << endl << f;
			bur.signForm( f );
		} catch( exception &e ) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n---------------------- Test 7 -----------------------");
		TEST( "beSigned + signForm / Already signed - KO");
		TEST( "------------------------------------------------------");
		try {
			Bureaucrat bur1( "Stew", 56);
			Bureaucrat bur2( "Bob", 32);
			Form f( "R2D2", 65, 65 );
			cout << "bur1: " << endl << bur1;
			cout << "bur2: " << endl << bur2;
			cout << "f: " << endl << f;
			bur1.signForm( f );
			bur2.signForm( f );
		} catch( exception &e ) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n---------------------- Test 8 -----------------------");
		TEST( "Basic Form class test");
		TEST( "----------------------- Const. -----------------------");
		Form	f;
		Form	f1( "R1", 7, 7 );
		Form	f2( f1 );
		Form	f3 = f2;
		TEST( "----------------------- Infos ------------------------");
		cout << "f:  " << endl << f;
		cout << "f1: " << endl << f1;
		cout << "f2: " << endl << f2;
		cout << "f3: " << endl << f3;
		TEST( "----------------------- Dest. ------------------------");
	}
	{
		TITLE( "\n---------------------- Test 9 -----------------------");
		TEST( "Deep copy test");
		TEST( "----------------------- Const. -----------------------");
		Form *f1 = new Form("C3PO", 42, 42);
		Form *f2 = new Form(*f1);
		Bureaucrat *bur = new Bureaucrat( "Bob", 27);
		TEST( "------------------------ Test ------------------------");
		cout << "Original: " << endl << *f1;
		cout << "Copy: " << endl << *f2;
		TEST( "---------------------- sign f1 ---------------------");
		try {
			bur->signForm( *f1 );
			cout << "Original: " << endl;
			cout << *f1;
			cout << "Copy: " << endl;
			cout << *f2;
		} catch( exception &e ) {
			cerr << e.what() << endl;
		}
		TEST( "\n---------------------- sign f2 ---------------------");
		try {
			bur->signForm( *f2 );
			cout << "Original: " << endl << *f1;
			cout << "Copy: " << endl << *f2;
		} catch( exception &e ) {
			cerr << e.what() << endl;
		}
		TEST( "----------------------- Dest. ------------------------");
		delete f1;
		delete f2;
		delete bur;
	}
	TITLE( "\n--------------------- End Tests ----------------------");
}