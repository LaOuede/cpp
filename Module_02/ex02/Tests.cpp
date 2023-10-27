/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/15 20:16:57 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"
#include "Fixed.hpp"

void runTests() {

	Fixed a = 20;
	Fixed b = 7.14f;

	TITLE( "\n**************** COMPARAISON OPERATORS ***************");
	TEST( "----------------------- Test 1 -----------------------");
	TEST( "	Test of \'<\' operator with " << a << " and " << b );
	cout << a << " < " << b << " : "<< (a < b ? "true" : "false") << endl;
	cout << b << " < " << a << " : "<< (b < a ? "true" : "false") << endl;
	cout << a << " < " << a << " : "<< (a < a ? "true" : "false") << endl;
	cout << b << " < " << b << " : "<< (b < b ? "true" : "false") << endl;

	TEST( "----------------------- Test 2 -----------------------");
	TEST( "	Test of \'>\' operator with " << a << " and " << b );
	cout << a << " > " << b << " : "<< (a > b ? "true" : "false") << endl;
	cout << b << " > " << a << " : "<< (b > a ? "true" : "false") << endl;
	cout << a << " > " << a << " : "<< (a > a ? "true" : "false") << endl;
	cout << b << " > " << b << " : "<< (b > b ? "true" : "false") << endl;

	TEST( "----------------------- Test 3 -----------------------");
	TEST( "	Test of \'<=\' operator with " << a << " and " << b );
	cout << a << " <= " << b << " : "<< (a <= b ? "true" : "false") << endl;
	cout << b << " <= " << a << " : "<< (b <= a ? "true" : "false") << endl;
	cout << a << " <= " << a << " : "<< (a <= a ? "true" : "false") << endl;
	cout << b << " <= " << b << " : "<< (b <= b ? "true" : "false") << endl;

	TEST( "----------------------- Test 4 -----------------------");
	TEST( "	Test of \'>=\' operator with " << a << " and " << b );
	cout << a << " >= " << b << " : "<< (a >= b ? "true" : "false") << endl;
	cout << b << " >= " << a << " : "<< (b >= a ? "true" : "false") << endl;
	cout << a << " >= " << a << " : "<< (a >= a ? "true" : "false") << endl;
	cout << b << " >= " << b << " : "<< (b >= b ? "true" : "false") << endl;

	TEST( "----------------------- Test 5 -----------------------");
	TEST( "	Test of \'==\' operator with " << a << " and " << b );
	cout << a << " == " << b << " : "<< (a == b ? "true" : "false") << endl;
	cout << b << " == " << a << " : "<< (b == a ? "true" : "false") << endl;
	cout << a << " == " << a << " : "<< (a == a ? "true" : "false") << endl;
	cout << b << " == " << b << " : "<< (b == b ? "true" : "false") << endl;

	TEST( "----------------------- Test 6 -----------------------");
	TEST( "	Test of \'!=\' operator with " << a << " and " << b );
	cout << a << " != " << b << " : "<< (a != b ? "true" : "false") << endl;
	cout << b << " != " << a << " : "<< (b != a ? "true" : "false") << endl;
	cout << a << " != " << a << " : "<< (a != a ? "true" : "false") << endl;
	cout << b << " != " << b << " : "<< (b != b ? "true" : "false") << endl;

	TITLE( "\n**************** ARITHMETIC OPERATORS ****************");
	TEST( "----------------------- Test 1 -----------------------");
	TEST( "	Test of \'+\' operator with " << a << " and " << b );
	cout << a << " + " << b << " = "<< (a + b) << endl;
	cout << b << " + " << a << " = "<< (b + a) << endl;
	cout << a << " + " << a << " = "<< (a + a) << endl;
	cout << b << " + " << b << " = "<< (b + b) << endl;

	TEST( "----------------------- Test 2 -----------------------");
	TEST( "	Test of \'-\' operator with " << a << " and " << b );
	cout << a << " - " << b << " = "<< (a - b) << endl;
	cout << b << " - " << a << " = "<< (b - a) << endl;
	cout << a << " - " << a << " = "<< (a - a) << endl;
	cout << b << " - " << b << " = "<< (b - b) << endl;

	TEST( "----------------------- Test 3 -----------------------");
	TEST( "Test of \'*\' operator with " << a << " and " << b );
	cout << a << " * " << b << " = "<< (a * b) << endl;
	cout << b << " * " << a << " = "<< (b * a) << endl;
	cout << a << " * " << a << " = "<< (a * a) << endl;
	cout << b << " * " << b << " = "<< (b * b) << endl;

	TEST( "----------------------- Test 4 -----------------------");
	TEST( "Test of \'/\' operator with" << a << " and " << b );
	cout << a << " / " << b << " = "<< (a / b) << endl;
	cout << b << " / " << a << " = "<< (b / a) << endl;
	cout << a << " / " << a << " = "<< (a / a) << endl;
	cout << b << " / " << b << " = "<< (b / b) << endl;

	TITLE( "\n****************** ++ & -- OPERATORS *****************");
	TEST( "----------------------- Test 1 -----------------------");
	TEST( "	Test of \'++(x)\' operator with " << a << " and " << b );
	cout << "++(" << a << ") = " << (++a) << endl;
	cout << "++(" << b << ") = " << (++b) << endl;

	TEST( "----------------------- Test 2 -----------------------");
	TEST( "	Test of \'--(x)\' operator with " << a << " and " << b );
	cout << "--(" << a << ") = " << (--a) << endl;
	cout << "--(" << b << ") = " << (--b) << endl;

	TEST( "----------------------- Test 3 -----------------------");
	TEST( "	Test of \'(x)++\' operator with " << a << " and " << b );
	cout << "(" << a << ")++" << " = " << (a++) << " : " << a << endl;
	cout << "(" << b << ")++" << " = " << (b++) << " : " << b << endl;

	TEST( "----------------------- Test 4 -----------------------");
	TEST( "	Test of \'(x)--\' operator with " << a << " and " << b );
	cout << "(" << a << ")--" << " = " << (a--) << " : " << a << endl;
	cout << "(" << b << ")--" << " = " << (b--) << " : " << b << endl;

	TITLE( "\n***************** MIN & MAX OPERATORS ****************");
	TEST( "----------------------- Test 1 -----------------------");
	TEST( "	Test of \'min\' operator with " << a << " and " << b );
	cout << "min(" << b << ", " << a << ") = " << Fixed::min( b, a ) << endl;
	cout << "min(" << b << ", " << b << ") = " << Fixed::min( b, b ) << endl;

	TEST( "----------------------- Test 2 -----------------------");
	TEST( "	Test of \'max\' operator with " << a << " and " << b );
	cout << "max(" << a << ", " << b << ") = " << Fixed::max( a, b ) << endl;
	cout << "max(" << a << ", " << a << ") = " << Fixed::max( a, a ) << endl;
	TITLE( "********************** END TESTS *********************");
}