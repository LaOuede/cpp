/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/15 20:17:40 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

void runTests() {
	{
		TEST( "----------------------- Test 1 -----------------------");
		Point a(0, 2);
		Point b(0, 0);
		Point c(2, 0);
		
		{
			POINT("1. point(0.25, 0.75)");
			Point point(0.25, 0.75);
			bool res = bsp(a, b, c, point);
			cout << "is inside triangle : " << (res == 1 ? "true" : "false") << endl;
		}
		{
			POINT("\n2. point(1, 0.5)");
			Point point(1, 0.5);
			bool res = bsp(a, b, c, point);
			cout << "is inside triangle : " << (res == 1 ? "true" : "false") << endl;
		}
		{
			POINT("\n3. point(2, 2)");
			Point point(2, 2);
			bool res = bsp(a, b, c, point);
			cout << "is inside triangle : " << (res == 1 ? "true" : "false") << endl;
		}
		{
			POINT("\n4. point(-2, 1)");
			Point point(-2, 1);
			bool res = bsp(a, b, c, point);
			cout << "is inside triangle : " << (res == 1 ? "true" : "false") << endl;
		}
		{
			POINT("\n5. point(2, 0)");
			Point point(2, 0);
			bool res = bsp(a, b, c, point);
			cout << "is inside triangle : " << (res == 1 ? "true" : "false") << endl;
		}
		{
			POINT("\n6. point(0.25, 0.25)");
			Point point(0.25, 0.25);
			bool res = bsp(a, b, c, point);
			cout << "is inside triangle : " << (res == 1 ? "true" : "false") << endl;
		}
		{
			POINT("\n7. point(-1, 1)");
			Point point(-1, 1);
			bool res = bsp(a, b, c, point);
			cout << "is inside triangle : " << (res == 1 ? "true" : "false") << endl;
		}
		{
			POINT("\n8. point(1.75, 0.2)");
			Point point(1.75, 0.2);
			bool res = bsp(a, b, c, point);
			cout << "is inside triangle : " << (res == 1 ? "true" : "false") << endl;
		}
	}
	{
		TEST( "----------------------- Test 2 -----------------------");
		Point a(2, -5);
		Point b(-2, -2);
		Point c(3, 1);
		
		{
			POINT("1. point(1, -2)");
			Point point(1, -2);
			bool res = bsp(a, b, c, point);
			cout << "is inside triangle : " << (res == 1 ? "true" : "false") << endl;
		}
		{
			POINT("\n2. point(-2, 4)");
			Point point(-2, 4);
			bool res = bsp(a, b, c, point);
			cout << "is inside triangle : " << (res == 1 ? "true" : "false") << endl;
		}
		{
			POINT("\n3. point(-2, -4)");
			Point point(-2, -4);
			bool res = bsp(a, b, c, point);
			cout << "is inside triangle : " << (res == 1 ? "true" : "false") << endl;
		}
		{
			POINT("\n4. point(0, 0)");
			Point point(0, 0);
			bool res = bsp(a, b, c, point);
			cout << "is inside triangle : " << (res == 1 ? "true" : "false") << endl;
		}
		{
			POINT("\n5. point(2, 0)");
			Point point(2, 0);
			bool res = bsp(a, b, c, point);
			cout << "is inside triangle : " << (res == 1 ? "true" : "false") << endl;
		}
		{
			POINT("\n6. point(-2, 0)");
			Point point(-2, 0);
			bool res = bsp(a, b, c, point);
			cout << "is inside triangle : " << (res == 1 ? "true" : "false") << endl;
		}
		{
			POINT("\n7. point(0, -3.5)");
			Point point(0, -3.5);
			bool res = bsp(a, b, c, point);
			cout << "is inside triangle : " << (res == 1 ? "true" : "false") << endl;
		}
		{
			POINT("\n8. point(3, 1)");
			Point point(3, 1);
			bool res = bsp(a, b, c, point);
			cout << "is inside triangle : " << (res == 1 ? "true" : "false") << endl;
		}
		{
			POINT("\n9. point(2, -5)");
			Point point(2, -5);
			bool res = bsp(a, b, c, point);
			cout << "is inside triangle : " << (res == 1 ? "true" : "false") << endl;
		}
		{
			POINT("\n10. point(-2, -2)");
			Point point(-2, -2);
			bool res = bsp(a, b, c, point);
			cout << "is inside triangle : " << (res == 1 ? "true" : "false") << endl;
		}
		{
			POINT("\n11. point(2, -1)");
			Point point(2, -1);
			bool res = bsp(a, b, c, point);
			cout << "is inside triangle : " << (res == 1 ? "true" : "false") << endl;
		}
	}
}