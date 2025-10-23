/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 22:26:16 by jow               #+#    #+#             */
/*   Updated: 2025/10/19 22:44:39 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed(): fpNum(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	//prevent self assignment
	if (this != &other)
		this->fpNum = other.getRawBits();
	return (*this);
}

Fixed::Fixed(int const value)
{
	std::cout << "Int constructor called" << std::endl;
	fpNum = value << bits;
}

Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	fpNum = static_cast<int>(roundf(value * float(1 << bits)));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

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
