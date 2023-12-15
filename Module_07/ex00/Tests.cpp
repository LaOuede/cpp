/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/30 11:52:46 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"
#include "Tests.hpp"

void runTests() {
	{
		TITLE( "-------------------- Subject Test --------------------");
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	{
		TITLE( "\n\n--------------------- SWAP TESTS ---------------------");
		TITLE( "----------------------- Test 1 -----------------------");
		TEST( "Swap int - OK");
		int a = 42;
		int b = -7;
		TEST( "------------------------ Test ------------------------");
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
		cout << "--- swap ---" << endl;
		::swap<int>( a, b );
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
	}
	{
		TITLE( "\n----------------------- Test 2 -----------------------");
		TEST( "Swap float - OK");
		float a = 42;
		float b = -7;
		TEST( "------------------------ Test ------------------------");
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
		cout << "--- swap ---" << endl;
		::swap<float>( a, b );
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
	}
	{
		TITLE( "\n----------------------- Test 3 -----------------------");
		TEST( "Swap unsigned int - OK");
		unsigned int a = 42;
		unsigned int b = 7;
		TEST( "------------------------ Test ------------------------");
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
		cout << "--- swap ---" << endl;
		::swap<unsigned int>( a, b );
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
	}
	{
		TITLE( "\n----------------------- Test 4 -----------------------");
		TEST( "Swap char - OK");
		char a = 'a';
		char b = 'b';
		TEST( "------------------------ Test ------------------------");
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
		cout << "--- swap ---" << endl;
		::swap<char>( a, b );
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
	}
	{
		TITLE( "\n----------------------- Test 5 -----------------------");
		TEST( "Swap double - OK");
		double a = 'a';
		double b = 'b';
		TEST( "------------------------ Test ------------------------");
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
		cout << "--- swap ---" << endl;
		::swap<double>( a, b );
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
	}
	{
		TITLE( "\n----------------------- Test 6 -----------------------");
		TEST( "Swap string - OK");
		string a = "Halloween";
		string b = "Christmas";
		TEST( "------------------------ Test ------------------------");
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
		cout << "--- swap ---" << endl;
		::swap<string>( a, b );
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
	}
	{
		TITLE( "\n----------------------- Test 7 -----------------------");
		TEST( "Swap same value - OK");
		int a = 42;
		int b = 42;
		TEST( "------------------------ Test ------------------------");
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
		cout << "--- swap ---" << endl;
		::swap<int>( a, b );
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
	}
	{
		TITLE( "\n\n--------------------- MIN. TESTS ---------------------");
		TITLE( "----------------------- Test 1 -----------------------");
		TEST( "Min. int - OK");
		int a = 42;
		int b = -7;
		TEST( "------------------------ Test ------------------------");
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
		cout << "--- min ---" << endl;
		cout << "Res: " << ::min<int>( a, b ) << endl;
	}
	{
		TITLE( "\n----------------------- Test 2 -----------------------");
		TEST( "Min. float - OK");
		float a = 42;
		float b = -7;
		TEST( "------------------------ Test ------------------------");
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
		cout << "--- min ---" << endl;
		cout << "Res: " << ::min<float>( a, b ) << endl;
	}
	{
		TITLE( "\n----------------------- Test 3 -----------------------");
		TEST( "Min. unsigned int - OK");
		unsigned int a = 42;
		unsigned int b = 7;
		TEST( "------------------------ Test ------------------------");
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
		cout << "--- min ---" << endl;
		cout << "Res: " << ::min<unsigned int>( a, b ) << endl;
	}
	{
		TITLE( "\n----------------------- Test 4 -----------------------");
		TEST( "Min. char - OK");
		char a = 'a';
		char b = 'b';
		TEST( "------------------------ Test ------------------------");
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
		cout << "--- min ---" << endl;
		cout << "Res: " << ::min<char>( a, b ) << endl;
	}
	{
		TITLE( "\n----------------------- Test 5 -----------------------");
		TEST( "Min. double - OK");
		double a = 'a';
		double b = 'b';
		TEST( "------------------------ Test ------------------------");
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
		cout << "--- min ---" << endl;
		cout << "Res: " << ::min<double>( a, b ) << endl;
	}
	{
		TITLE( "\n----------------------- Test 6 -----------------------");
		TEST( "Min. string - OK");
		string a = "Halloween1";
		string b = "Halloween2";
		TEST( "------------------------ Test ------------------------");
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
		cout << "--- min ---" << endl;
		cout << "Res: " << ::min<string>( a, b ) << endl;
	}
	{
		TITLE( "\n----------------------- Test 7 -----------------------");
		TEST( "Min. same value - OK");
		int a = 42;
		int b = 42;
		TEST( "------------------------ Test ------------------------");
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
		cout << "--- min ---" << endl;
		cout << "Res: " << ::min<int>( a, b ) << endl;
	}
	{
		TITLE( "\n\n--------------------- Max. TESTS ---------------------");
		TITLE( "----------------------- Test 1 -----------------------");
		TEST( "Max. int - OK");
		int a = 42;
		int b = -7;
		TEST( "------------------------ Test ------------------------");
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
		cout << "--- max ---" << endl;
		cout << "Res: " << ::max<int>( a, b ) << endl;
	}
	{
		TITLE( "\n----------------------- Test 2 -----------------------");
		TEST( "Max. float - OK");
		float a = 42;
		float b = -7;
		TEST( "------------------------ Test ------------------------");
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
		cout << "--- max ---" << endl;
		cout << "Res: " << ::max<float>( a, b ) << endl;
	}
	{
		TITLE( "\n----------------------- Test 3 -----------------------");
		TEST( "Max. unsigned int - OK");
		unsigned int a = 42;
		unsigned int b = 7;
		TEST( "------------------------ Test ------------------------");
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
		cout << "--- max ---" << endl;
		cout << "Res: " << ::max<unsigned int>( a, b ) << endl;
	}
	{
		TITLE( "\n----------------------- Test 4 -----------------------");
		TEST( "Max. char - OK");
		char a = 'a';
		char b = 'b';
		TEST( "------------------------ Test ------------------------");
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
		cout << "--- max ---" << endl;
		cout << "Res: " << ::max<char>( a, b ) << endl;
	}
	{
		TITLE( "\n----------------------- Test 5 -----------------------");
		TEST( "Max. double - OK");
		double a = 'a';
		double b = 'b';
		TEST( "------------------------ Test ------------------------");
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
		cout << "--- max ---" << endl;
		cout << "Res: " << ::max<double>( a, b ) << endl;
	}
	{
		TITLE( "\n----------------------- Test 6 -----------------------");
		TEST( "Max. string - OK");
		string a = "Halloween1";
		string b = "Halloween2";
		TEST( "------------------------ Test ------------------------");
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
		cout << "--- max ---" << endl;
		cout << "Res: " << ::max<string>( a, b ) << endl;
	}
	{
		TITLE( "\n----------------------- Test 7 -----------------------");
		TEST( "Max. same value - OK");
		int a = 42;
		int b = 42;
		TEST( "------------------------ Test ------------------------");
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
		cout << "--- max ---" << endl;
		cout << "Res: " << ::max<int>( a, b ) << endl;
	}
	TITLE( "\n--------------------- End Tests ----------------------");
}