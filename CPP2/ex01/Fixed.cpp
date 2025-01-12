/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:20:25 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/07 23:55:32 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default Constructor
Fixed::Fixed(void): _rawValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other): _rawValue(other._rawValue)
{
	std::cout << "Copy constructor called" << std::endl;	
	*this = other;
}

// Assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	_rawValue = other.getRawBits();
	return (*this);
}

// Destructor
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

// rawBits = bits where there is the rawValue
int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (_rawValue);
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	_rawValue = raw;
}

// Constructor of Fixed from an Int via !!! rawValue !!!
// On construit un fixed-point a partir d'un entier
// In fixed-point arithmetic, the bit shift "value << fractionalBits" is used to position
// the integer part correctly within _rawBits while leaving space for the fractional part.
Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	if (n > INT_MAX / 256 || n < INT_MIN / 256) //-8388608_8388607
		std::cerr << "Overflow (out of INT type range)" << std::endl;
	_rawValue = n << _frBits; // n * 2^frBits = n * 2^8
}

// Constructor of Fixed from a Float via !!! rawValue !!!
// On construit un fixed-point a partir d'un float
// f * (1 << _frBits) converts the floating-point number f into a scaled
// integer representation suitable for fixed-point storage.
Fixed::Fixed(const float f)
{
	float n = roundf(f * (1 << _frBits));
	// std::cout << "n " << n << std::endl;
	std::cout << "Float constructor called" << std::endl;
	if (n > INT_MAX || n < INT_MIN )
		std::cerr << "Overflow (out of INT type range)" << std::endl;
	_rawValue = roundf(f * (1 << _frBits)); // 1 * 2^frBits = 1 * 2^8
	// std::cout << "_rawValue" <<  _rawValue << std::endl;
}

// Converts Fixed in Float
// second float cast is safer than nothing 
float Fixed::toFloat(void) const
{
	return ((float)_rawValue / (float)(1 << _frBits));
}

// Converts Fixed in Int
// Fixed point is store in rawBits, with one chunk the ingeter and fractional part 
int Fixed::toInt(void) const
{
	return (_rawValue >> _frBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out); 	
}
