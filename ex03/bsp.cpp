/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 02:50:08 by jow               #+#    #+#             */
/*   Updated: 2025/10/20 14:42:30 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

static Fixed calculateArea(Point const a, Point const b, Point const c)
{
	Fixed area;

	// Area = 0.5|x1(y2-y3) + x2(y3-y1) + x3(y1-y2)|
    area = Fixed(0.5f) * (a.get_x() * (b.get_y() - c.get_y()) + b.get_x() * (c.get_y() - a.get_y()) + c.get_x() * 
		(a.get_y() - b.get_y()));
	if (area < Fixed(0))
		area = area * Fixed(-1);
    return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed totalArea;
	Fixed triAPointB;
	Fixed triAPointC;
	Fixed triBPointC;
	Fixed sumOfTri;

	totalArea = calculateArea(a, b, c);
	triAPointB = calculateArea(a, point, b);
	triAPointC = calculateArea(a, point, c);
	triBPointC = calculateArea(b, point, c);
	sumOfTri = triAPointB + triAPointC + triBPointC;
	if (triAPointB != 0 && triAPointC != 0 && triBPointC!= 0 && totalArea == sumOfTri)
		return (true);
	else
		return (false);
}