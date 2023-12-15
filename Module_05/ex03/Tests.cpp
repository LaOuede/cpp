/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/02 21:18:46 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"

void runTests() {
	TITLE( "--------------------- INTERN TESTS ---------------------");
	{
		TITLE( "\n------------------------ Test 1 ------------------------");
		TEST( "🌳 ShrubberyCreationForm test - OK");
		TEST( "------------------------ Const. ------------------------");
		Intern randomIntern;
		Bureaucrat bur( "Bob", 45 );
		AForm *f;
		try {
			TEST( "-------------------------- Test ------------------------");
			cout << "bur: " << endl << bur;
			f = randomIntern.makeForm ( "shrubbery creation", "garden" );
			cout << "f: " << endl << *f;
			bur.signForm( *f );
			bur.executeForm( *f );
			TEST( "------------------------- Dest. ------------------------");
		} catch( exception &e ) {
			cerr << e.what() << endl;
		}
		delete f;
	}
	{
		TITLE( "\n------------------------ Test 2 ------------------------");
		TEST( "🦾 RobotomyRequestForm test - OK");
		TEST( "------------------------ Const. ------------------------");
		Intern randomIntern;
		Bureaucrat bur( "Bob", 37 );
		AForm *f;
		try {
			TEST( "-------------------------- Test ------------------------");
			cout << "bur: " << endl << bur;
			f = randomIntern.makeForm ( "robotomy request", "C3P0" );
			cout << "f: " << endl << *f;
			bur.signForm( *f );
			bur.executeForm( *f );
			TEST( "------------------------- Dest. ------------------------");
		} catch( exception &e ) {
			cerr << e.what() << endl;
		}
		delete f;
	}
	{
		TITLE( "\n------------------------ Test 3 ------------------------");
		TEST( "🎁 PresidentialPardonForm test - OK");
		TEST( "------------------------ Const. ------------------------");
		Intern randomIntern;
		Bureaucrat bur( "Sully", 4 );
		AForm *f;
		try {
			TEST( "-------------------------- Test ------------------------");
			cout << "bur: " << endl << bur;
			f = randomIntern.makeForm ( "presidential pardon", "Bob Razowski" );
			cout << "f: " << endl << *f;
			bur.signForm( *f );
			bur.executeForm( *f );
			TEST( "------------------------- Dest. ------------------------");
		} catch( exception &e ) {
			cerr << e.what() << endl;
		}
		delete f;
	}
	{
		TITLE( "\n------------------------ Test 4 ------------------------");
		TEST( "Subject test - OK");
		try {
			TEST( "------------------------ Const. ------------------------");
			Intern someRandomIntern;
			AForm* rrf;
			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
			cout << *rrf;
			TEST( "------------------------- Dest. ------------------------");
		} catch( exception &e ) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n------------------------ Test 5 ------------------------");
		TEST( " Fail test / bad form name - KO");
		TEST( "------------------------ Const. ------------------------");
		Intern randomIntern;
		Bureaucrat bur( "R1", 65 );
		AForm *f;
		try {
			TEST( "-------------------------- Test ------------------------");
			cout << "bur: " << endl << bur;
			f = randomIntern.makeForm ( "random form", "Bob Razowski" );
			cout << "f: " << endl << *f;
			bur.signForm( *f );
			bur.executeForm( *f );
			TEST( "------------------------- Dest. ------------------------");
		} catch( exception &e ) {
			cerr << e.what() << endl;
		}
	}
	TITLE( "\n---------------------- End Tests -----------------------");
}