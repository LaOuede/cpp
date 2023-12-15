/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/29 08:31:50 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"
#include "Tests.hpp"

void runTests() {
	{
		TITLE( "----------------------- Test 1 -----------------------");
		TEST( "findType() test : argument type - OK");
		try {
			Conversion c1("a");
			Conversion c2("28");
			Conversion c3("647832346342");
			Conversion c4("42.0f");
			Conversion c5("+inff");
			Conversion c6("nan");
			TEST( "------------------------ Test ------------------------");
			cout << c1 << endl;
			cout << c2 << endl;
			cout << c3 << endl;
			cout << c4 << endl;
			cout << c5 << endl;
			cout << c6 << endl;
		} catch( exception &e ) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "----------------------- Test 2 -----------------------");
		TEST( "Char test : argument type - OK");
		try {
			Conversion c("a");
			TEST( "------------------------ Test ------------------------");
			cout << c << endl;
		} catch( exception &e ) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "----------------------- Test 3 -----------------------");
		TEST( "Int test : argument type - OK");
		try {
			Conversion c("123456789");
			TEST( "------------------------ Test ------------------------");
			cout << c << endl;
		} catch( exception &e ) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "----------------------- Test 4 -----------------------");
		TEST( "Double test : argument type - OK");
		try {
			Conversion c("42.24");
			TEST( "------------------------ Test ------------------------");
			cout << c << endl;
		} catch( exception &e ) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "----------------------- Test 5 -----------------------");
		TEST( "Float test : argument type - OK");
		try {
			Conversion c("42.24f");
			TEST( "------------------------ Test ------------------------");
			cout << c << endl;
		} catch( exception &e ) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "----------------------- Test 6 -----------------------");
		TEST( "Special test : argument type - OK");
		try {
			Conversion c("+inf");
			TEST( "------------------------ Test ------------------------");
			cout << c << endl;
		} catch( exception &e ) {
			cerr << e.what() << endl;
		}
	}
	{
		TITLE( "----------------------- Test 7 -----------------------");
		TEST( "Error test : argument type - OK");
		try {
			Conversion c("Goodbye and thanks for all the fish");
			TEST( "------------------------ Test ------------------------");
			cout << c << endl;
		} catch( exception &e ) {
			cerr << e.what() << endl;
		}
	}
	TITLE( "--------------------- End Tests ----------------------");
}