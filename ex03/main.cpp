/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 02:52:10 by jow               #+#    #+#             */
/*   Updated: 2025/10/20 14:52:35 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	Point a(0, 0);
	Point b(1, 1);
	Point c(0, 1);

	Point point(1,1);

	std::cout << "a [x-coord]" << a.get_x().toFloat();
	std::cout << " [y-coord]" << a.get_y().toFloat() << std::endl;
	std::cout << "b [x-coord]" << b.get_x().toFloat();
	std::cout << " [y-coord]" << b.get_y().toFloat() << std::endl;
	std::cout << "c [x-coord]" << c.get_x().toFloat();
	std::cout << " [y-coord]" << c.get_y().toFloat() << std::endl;
	std::cout << "P [x-coord]" << point.get_x().toFloat();
	std::cout << " [y-coord]" << point.get_y().toFloat() << std::endl;

	if (bsp(a, b, c, point))
		std::cout << "point is in triangle abc" << std::endl;
	else
		std::cout << "point is NOT in triangle abc" << std::endl;
		
	
}

/*
void testBSP(Point const a, Point const b, Point const c, Point const p, std::string label)
{
	std::cout << "---- " << label << " ----" << std::endl;
	std::cout << "Triangle: A(" << a.get_x().toFloat() << "," << a.get_y().toFloat() << "), "
			  << "B(" << b.get_x().toFloat() << "," << b.get_y().toFloat() << "), "
			  << "C(" << c.get_x().toFloat() << "," << c.get_y().toFloat() << ")\n";
	std::cout << "Point: P(" << p.get_x().toFloat() << "," << p.get_y().toFloat() << ")\n";

	if (bsp(a, b, c, p))
		std::cout << "Point is INSIDE the triangle.\n";
	else
		std::cout << "Point is OUTSIDE the triangle.\n";
	std::cout << std::endl;
}

int main(void)
{
	Point a(0, 0);
	Point b(1, 1);
	Point c(0, 1);
	
	testBSP(a, b, c, Point(0.5f, 0.5f), "On edge AB");
	testBSP(a, b, c, Point(1, 1), "On vertex B");
	testBSP(a, b, c, Point(0, 0.5f), "On edge AC");
	testBSP(a, b, c, Point(0.7f, 0.2f), "Outside near AB");

	Point d(0, 0);
	Point e(10, 0);
	Point f(0, 10);
	testBSP(d, e, f, Point(3, 3), "Inside large triangle");
	testBSP(d, e, f, Point(10, 10), "Clearly outside");
	testBSP(d, e, f, Point(5, 0), "On base edge");
	
	Point g(-1, -1);
	Point h(-3, -1);
	Point i(-2, -3);
	testBSP(g, h, i, Point(-2, -2), "Inside negative coordinates triangle");
	testBSP(g, h, i, Point(0, 0), "Outside negative coordinates triangle");

	Point j(0.0f, 0.0f);
	Point k(0.0001f, 1.0001f);
	Point l(1.0001f, 0.0001f);
	testBSP(j, k, l, Point(0.3f, 0.3f), "Inside floating point triangle");
	testBSP(j, k, l, Point(2.0f, 2.0f), "Far outside triangle");

	return 0;
}
*/
