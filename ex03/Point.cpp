/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 03:01:01 by jow               #+#    #+#             */
/*   Updated: 2025/10/20 14:10:32 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::~Point() {}

Point::Point(const float a, const float b) : x(a), y(b) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point &Point::operator=(const Point &other)
{
    (void)other;
    std::cerr << "Error: assignment to const Point is not allowed" << std::endl;
    return *this;
}

Fixed Point::get_x(void) const {return x;}
Fixed Point::get_y(void) const {return y;}