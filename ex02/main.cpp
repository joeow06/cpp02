/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 22:25:57 by jow               #+#    #+#             */
/*   Updated: 2025/10/20 02:43:28 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// int main( void ) 
// {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
	
	
// 	return 0;
// }


int main(void)
{
	std::cout << "===== Constructors & Assignment =====" << std::endl;
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	a = Fixed(1234.4321f);

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;

	std::cout << "\n===== Comparison Operators =====" << std::endl;
	Fixed x(10);
	Fixed y(20);
	std::cout << "(x < y): " << (x < y) << std::endl;
	std::cout << "(x > y): " << (x > y) << std::endl;
	std::cout << "(x <= y): " << (x <= y) << std::endl;
	std::cout << "(x >= y): " << (x >= y) << std::endl;
	std::cout << "(x == y): " << (x == y) << std::endl;
	std::cout << "(x != y): " << (x != y) << std::endl;

	std::cout << "\n===== Arithmetic Operators =====" << std::endl;
	Fixed num1(5.05f);
	Fixed num2(2);
	std::cout << "num1 + num2 = " << (num1 + num2) << std::endl;
	std::cout << "num1 - num2 = " << (num1 - num2) << std::endl;
	std::cout << "num1 * num2 = " << (num1 * num2) << std::endl;
	std::cout << "num1 / num2 = " << (num1 / num2) << std::endl;

	std::cout << "\n===== Increment & Decrement =====" << std::endl;
	Fixed inc;
	std::cout << "Initial: " << inc << std::endl;
	std::cout << "++inc:   " << ++inc << std::endl;
	std::cout << "inc:     " << inc << std::endl;
	std::cout << "inc++:   " << inc++ << std::endl;
	std::cout << "inc:     " << inc << std::endl;
	std::cout << "--inc:   " << --inc << std::endl;
	std::cout << "inc:     " << inc << std::endl;
	std::cout << "inc--:   " << inc-- << std::endl;
	std::cout << "inc:     " << inc << std::endl;

	std::cout << "\n===== Min & Max =====" << std::endl;
	Fixed e(3.3f);
	Fixed f(6.6f);
	const Fixed g(9.9f);
	const Fixed h(1.1f);
	std::cout << "Values: " << std::endl;
	std::cout << "e: "<< e << ", f: " << f << ", g: " << g << ", h: " << h << std::endl; 

	std::cout << "min(e, f): " << Fixed::min(e, f) << std::endl;
	std::cout << "max(e, f): " << Fixed::max(e, f) << std::endl;
	std::cout << "min(g, h): " << Fixed::min(g, h) << std::endl;
	std::cout << "max(g, h): " << Fixed::max(g, h) << std::endl;

	return 0;
}
