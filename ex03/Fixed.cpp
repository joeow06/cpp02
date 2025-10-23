/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 22:26:16 by jow               #+#    #+#             */
/*   Updated: 2025/10/20 00:02:48 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed(): fpNum(0) {}

Fixed::Fixed(const Fixed &other) {*this = other;}

Fixed &Fixed::operator=(const Fixed &other)
{
	//prevent self assignment
	if (this != &other)
		this->fpNum = other.getRawBits();
	return (*this);
}

Fixed::Fixed(int const value) {fpNum = value << bits;}

Fixed::Fixed(float const value)
{
	fpNum = static_cast<int>(roundf(value * float(1 << bits)));
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const
{
	return (fpNum);
}

void Fixed::setRawBits(int const raw)
{
	fpNum = raw;
}

float Fixed::toFloat( void ) const
{
	return (float(this->fpNum) / (1 << bits));
}

int Fixed::toInt( void ) const
{
	return (this->fpNum >> Fixed::bits);
}

std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
	out << value.toFloat();
	return (out);
}

bool Fixed::operator>(const Fixed &other) const { return this->fpNum > other.fpNum; }
bool Fixed::operator<(const Fixed &other) const { return this->fpNum < other.fpNum; }
bool Fixed::operator>=(const Fixed &other) const { return this->fpNum >= other.fpNum; }
bool Fixed::operator<=(const Fixed &other) const { return this->fpNum <= other.fpNum; }
bool Fixed::operator==(const Fixed &other) const { return this->fpNum == other.fpNum; }
bool Fixed::operator!=(const Fixed &other) const { return this->fpNum != other.fpNum; }

Fixed Fixed::operator+(const Fixed &other ) const
{
	Fixed result;
	result.setRawBits(this->fpNum + other.fpNum);
	return result;
}

Fixed Fixed::operator-(const Fixed &other ) const
{
	Fixed result;
	result.setRawBits(this->fpNum - other.fpNum);
	return result;
}

Fixed Fixed::operator*(const Fixed &other ) const
{
	Fixed result;
	result.setRawBits((this->fpNum * other.fpNum) >> bits);
	return result;
}

Fixed Fixed::operator/(const Fixed &other ) const
{
	Fixed result;
	result.setRawBits((this->fpNum << bits) / other.fpNum);
	return result;
}

Fixed& Fixed::operator++()
{
	fpNum += 1;
	return (*this);
}

Fixed& Fixed::operator--()
{
	fpNum -= 1;
	return (*this);
}

// (int) is just a dummy to distinguish postfix from prefix
// Make a copy, increment myself using pre-increment, return copy
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++(*this);
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--(*this);
	return (tmp);		
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}