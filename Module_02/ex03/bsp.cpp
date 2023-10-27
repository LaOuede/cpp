/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/15 20:17:08 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool checkNeg(float tmp1, float tmp2, float tmp3) {
	return (tmp1 < 0) || (tmp2 < 0) || (tmp3 < 0) ? true : false;
}

bool checkNull(float tmp1, float tmp2, float tmp3) {
	return (tmp1 == 0) || (tmp2 == 0) || (tmp3 == 0) ? true : false;
}

bool checkPoint(Point const a, Point const b, Point const c, Point const point) {
	return (a.getX() == point.getX() && a.getY() == point.getY())
		|| (b.getX() == point.getX() && b.getY() == point.getY())
		|| (c.getX() == point.getX() && c.getY() == point.getY()) ? true : false;
}

Fixed areaCalcul(Point const A, Point const B, Point const C) {
	return ((A.getX() - B.getX()) * (A.getY() - C.getY()) + (C.getX() - A.getX()) * (A.getY() - B.getY())) / 2;
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	// Triangle ABC area
	Fixed area = areaCalcul(a, b, c);
	float tmp = area.toFloat();

	// Other triangles areas
	Fixed abpoint = areaCalcul(a, b, point);
	float tmp1 = abpoint.toFloat();

	Fixed acpoint = areaCalcul(a, c, point);
	float tmp2 = acpoint.toFloat();

	Fixed bcpoint = areaCalcul(b, c, point);
	float tmp3 = bcpoint.toFloat();

	float total = fabs(tmp1) + fabs(tmp2) + fabs(tmp3);

	if (DEBUG){
		printf("ABC area     = %f\n", tmp);
		printf("ABPoint area = %f\n", tmp1);
		printf("ACPoint area = %f\n", tmp2);
		printf("BCPoint area = %f\n", tmp3);
		printf("total        = %f\n", total);
		printf("diff = %d\n", total == fabs(tmp));
		printf("neg  = %d\n", checkNeg(tmp1, tmp2, tmp3));
		printf("null = %d\n", checkNull(tmp1, tmp2, tmp3));
		printf("dup  = %d\n", checkPoint(a, b, c, point));
	}
	if (checkPoint(a, b, c, point))
		return false;
	return (total == fabs(tmp)) && (!checkNeg(tmp1, tmp2, tmp3) || !checkNull(tmp1, tmp2, tmp3)) ? true : false;
}