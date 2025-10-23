/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 22:26:51 by jow               #+#    #+#             */
/*   Updated: 2025/10/19 23:52:42 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int fpNum;
		static const int bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &other);
		~Fixed();
		Fixed(int const value);
		Fixed(float const value);
		Fixed &operator=(const Fixed &other);
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		
		bool operator>(const Fixed &other ) const;
		bool operator<(const Fixed &other ) const;
		bool operator>=(const Fixed &other ) const;
		bool operator<=(const Fixed &other ) const;
		bool operator==(const Fixed &other ) const;
		bool operator!=(const Fixed &other ) const;

		Fixed operator+(const Fixed &other ) const;
		Fixed operator-(const Fixed &other ) const;
		Fixed operator*(const Fixed &other ) const;
		Fixed operator/(const Fixed &other ) const;
		
		Fixed &operator++();
		Fixed &operator--();
		Fixed operator++(int);
		Fixed operator--(int);

		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);

#endif