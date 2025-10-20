/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 02:46:41 by jow               #+#    #+#             */
/*   Updated: 2025/10/20 14:10:20 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

# include <iostream>
# include <cmath>
# include "Fixed.hpp"

class Point {
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		~Point();
		Point(const float a, const float b);
		Point(const Point &other);
		Point &operator=(const Point &other);
		Fixed get_x(void) const;
		Fixed get_y(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif