/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/02 21:58:47 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"

void runTests() {
	TITLE( "------------------- SHRUBBERY TESTS --------------------");
	{
		TITLE( "------------------------ Test 1 ------------------------");
		TEST( "ShrubberyCreationForm class test - OK");
		TEST( "------------------------ Const. ------------------------");
		ShrubberyCreationForm f1;
		ShrubberyCreationForm f2( f1 );
		ShrubberyCreationForm f3 = f2;
		TEST( "------------------------ Infos -------------------------");
		cout << "f1: " << endl << f1;
		cout << "f2: " << endl << f2;
		cout << "f3: " << endl << f3;
		TEST( "------------------------ Dest. -------------------------");
	}
	{
		TITLE( "\n------------------------ Test 2 ------------------------");
		TEST( "execute test - OK");
		try {
			TEST( "------------------------ Const. ------------------------");
			Bureaucrat bur( "Bob", 45 );
			ShrubberyCreationForm f( "garden" );
			TEST( "-------------------------- Test ------------------------");
			cout << "bur: " << endl << bur;
			cout << "f: " << endl << f;
			bur.signForm( f );
			bur.executeForm( f );
			TEST( "------------------------- Dest. ------------------------");
		} catch( exception &e ) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n------------------------ Test 3 ------------------------");
		TEST( "execute test / grade to low to exec - KO");
		try {
			TEST( "------------------------ Const. ------------------------");
			Bureaucrat bur( "Bob", 143 );
			ShrubberyCreationForm f( "garden" );
			TEST( "-------------------------- Test ------------------------");
			cout << "bur: " << endl << bur;
			cout << "f: " << endl << f;
			bur.signForm( f );
			bur.executeForm( f );
		} catch( exception &e ) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n------------------------ Test 4 ------------------------");
		TEST( "execute test / grade to low to sign - KO");
		try {
			TEST( "------------------------ Const. ------------------------");
			Bureaucrat bur( "Bob", 149 );
			ShrubberyCreationForm f( "garden" );
			TEST( "-------------------------- Test ------------------------");
			cout << "bur: " << endl << bur;
			cout << "f: " << endl << f;
			bur.signForm( f );
			bur.executeForm( f );
		} catch( exception &e ) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n------------------------ Test 5 ------------------------");
		TEST( "execute test / form not signed - KO");
		try {
			TEST( "------------------------ Const. ------------------------");
			Bureaucrat bur( "Bob", 34 );
			ShrubberyCreationForm f( "garden" );
			TEST( "-------------------------- Test ------------------------");
			cout << "bur: " << endl << bur;
			cout << "f: " << endl << f;
			bur.executeForm( f );
		} catch( exception &e ) {
			cerr << e.what() << endl;
		}
	}
	TITLE( "\n\n-------------------- ROBOTOMY TESTS --------------------");
	{
		TITLE( "------------------------ Test 1 ------------------------");
		TEST( "RobotomyRequestForm class test - OK");
		TEST( "------------------------ Const. ------------------------");
		RobotomyRequestForm f1;
		RobotomyRequestForm f2( f1 );
		RobotomyRequestForm f3 = f2;
		TEST( "------------------------ Infos -------------------------");
		cout << "f1: " << endl << f1;
		cout << "f2: " << endl << f2;
		cout << "f3: " << endl << f3;
		TEST( "------------------------ Dest. -------------------------");
	}
	{
		TITLE( "\n------------------------ Test 2 ------------------------");
		TEST( "execute test - OK");
		try {
			TEST( "------------------------ Const. ------------------------");
			Bureaucrat bur( "Bob", 45 );
			RobotomyRequestForm f( "C3PO" );
			TEST( "-------------------------- Test ------------------------");
			cout << "bur: " << endl << bur;
			cout << "f: " << endl << f;
			bur.signForm( f );
			bur.executeForm( f );
			TEST( "------------------------ Dest. -------------------------");
		} catch( exception &e ) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n------------------------ Test 3 ------------------------");
		TEST( "execute test / grade to low to exec - KO");
		try {
			TEST( "------------------------ Const. ------------------------");
			Bureaucrat bur( "Bob", 56 );
			RobotomyRequestForm f( "R2D2" );
			TEST( "-------------------------- Test ------------------------");
			cout << "bur: " << endl << bur;
			cout << "f: " << endl << f;
			bur.signForm( f );
			bur.executeForm( f );
		} catch( exception &e ) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n------------------------ Test 4 ------------------------");
		TEST( "execute test / grade to low to sign - KO");
		try {
			TEST( "------------------------ Const. ------------------------");
			Bureaucrat bur( "Bob", 149 );
			RobotomyRequestForm f( "R2D2" );
			TEST( "-------------------------- Test ------------------------");
			cout << "bur: " << endl << bur;
			cout << "f: " << endl << f;
			bur.signForm( f );
			bur.executeForm( f );
		} catch( exception &e ) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n------------------------ Test 5 ------------------------");
		TEST( "execute test / form not signed - KO");
		try {
			TEST( "------------------------ Const. ------------------------");
			Bureaucrat bur( "Bob", 34 );
			RobotomyRequestForm f( "R2D2" );
			TEST( "-------------------------- Test ------------------------");
			cout << "bur: " << endl << bur;
			cout << "f: " << endl << f;
			bur.executeForm( f );
		} catch( exception &e ) {
			cerr << e.what() << endl;
		}
	}
		TITLE( "\n\n------------------ PRESIDENTIAL TESTS ------------------");
	{
		TITLE( "------------------------ Test 1 ------------------------");
		TEST( "RobotomyRequestForm class test - OK");
		TEST( "------------------------ Const. ------------------------");
		PresidentialPardonForm f1;
		PresidentialPardonForm f2( f1 );
		PresidentialPardonForm f3 = f2;
		TEST( "------------------------ Infos -------------------------");
		cout << "f1: " << endl << f1;
		cout << "f2: " << endl << f2;
		cout << "f3: " << endl << f3;
		TEST( "------------------------ Dest. -------------------------");
	}
	{
		TITLE( "\n------------------------ Test 2 ------------------------");
		TEST( "execute test - OK");
		try {
			TEST( "------------------------ Const. ------------------------");
			Bureaucrat bur( "Sully", 2 );
			PresidentialPardonForm f( "Bob Razowski" );
			TEST( "-------------------------- Test ------------------------");
			cout << "bur: " << endl << bur;
			cout << "f: " << endl << f;
			bur.signForm( f );
			bur.executeForm( f );
			TEST( "------------------------ Dest. -------------------------");
		} catch( exception &e ) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n------------------------ Test 3 ------------------------");
		TEST( "execute test / grade to low to exec - KO");
		try {
			TEST( "------------------------ Const. ------------------------");
			Bureaucrat bur( "Sully", 7 );
			PresidentialPardonForm f( "Bob Razowski" );
			TEST( "-------------------------- Test ------------------------");
			cout << "bur: " << endl << bur;
			cout << "f: " << endl << f;
			bur.signForm( f );
			bur.executeForm( f );
		} catch( exception &e ) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n------------------------ Test 4 ------------------------");
		TEST( "execute test / grade to low to sign - KO");
		try {
			TEST( "------------------------ Const. ------------------------");
			Bureaucrat bur( "Sully", 35 );
			PresidentialPardonForm f( "Bob Razowski" );
			TEST( "-------------------------- Test ------------------------");
			cout << "bur: " << endl << bur;
			cout << "f: " << endl << f;
			bur.signForm( f );
			bur.executeForm( f );
		} catch( exception &e ) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "\n------------------------ Test 5 ------------------------");
		TEST( "execute test / form not signed - KO");
		try {
			TEST( "------------------------ Const. ------------------------");
			Bureaucrat bur( "Sully", 3 );
			PresidentialPardonForm f( "Bob Razowski" );
			TEST( "-------------------------- Test ------------------------");
			cout << "bur: " << endl << bur;
			cout << "f: " << endl << f;
			bur.executeForm( f );
		} catch( exception &e ) {
			cerr << e.what() << endl;
		}
	}
	TITLE( "\n---------------------- End Tests -----------------------");
}