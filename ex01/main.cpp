/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 22:25:57 by jow               #+#    #+#             */
/*   Updated: 2025/10/19 22:35:37 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{
	Fixed 		a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	
	a = Fixed( 1234.4321f );
	
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return (0);
}

/*
A fixed-point number is a way of representing real numbers (fractions and integers) 
using integers underneath — by fixing a certain number of bits to represent the fractional part.

Fixed Point vs Floating Point Numbers:

Fixed:
- Fixed Range (depends on how many bits u assign to integer and fractional parts.)
- Accuracy is exact for representable numbers — no rounding errors.
- Limited dynamic range — can’t represent very large or very small numbers.
- Common in embedded systems or financial calculations

Floating:
- Dynamic range — can represent very large and very small numbers (mantissa & exponent)
- Good precision, but poor accuracy

How Fixed Point Number is represented:
1. We set the fractional bits to 8, so for a 32-bit integer, top 24 bits are integer,
	last 8 bits are fractional part
2. To do so, we have to right shift (<<) by 8 which also equals multiply 256
	Example: real number -> 3.5
			 fpNum		 -> 768
			 binary 	 -> 0000001110000000 (use 16-bit as example only)
3. For our program, we construct from either Int or Float
4. When constructing from Int, fpNum == value << bits (multiply number by 256)
5. When constructing from Float, fpNum = static_cast<int>(std::roundf(value * (1 << bits)));
6. Then we store the result from 4. and 5. in fpNum, as integers (e.g. 768 for value 3.5)
7. We convert fpNum back when we want to use the numbers
8. When converting back to int, return (this->fpNum >> bits); 
		--Shifts right by 8 bits (divide by 256, discarding fractional part)--
9. When converting back to float, return (float(this->fpNum) / (1 << bits));
		-- Divides by 256 to get back the real value--

*/