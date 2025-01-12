/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:20:25 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/08 00:22:15 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default Constructor
Fixed::Fixed(void) : _rawValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other) : _rawValue(other._rawValue)
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
int Fixed::getRawBits(void) const
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
Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	if (n > INT_MAX / 256 || n < INT_MIN / 256) //-8388608_8388607
		std::cerr << "!!! Overflow (out of INT type range)" << std::endl;
	_rawValue = n << _frBits; // n * 2^frBits = n * 2^8
}

// Constructor of Fixed from a Float via !!! rawValue !!!
Fixed::Fixed(const float f)
{
	float n = roundf(f * (1 << _frBits));
	std::cout << "Float constructor called" << std::endl;
	if (n > INT_MAX || n < INT_MIN )
		std::cerr << "!!! Overflow (out of INT type range)" << std::endl;
	_rawValue = roundf(f * (1 << _frBits)); // 1 * 2^frBits = 1 * 2^8
}

// Converts Fixed in Float
float Fixed::toFloat(void) const
{
	return ((float)_rawValue / (float)(1 << _frBits));
}

// Converts Fixed in Int
int Fixed::toInt(void) const
{
	return (_rawValue >> _frBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

// Comparison operators overloaded
bool Fixed::operator>(const Fixed &other) const
{
	return (_rawValue > other._rawValue);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (_rawValue < other._rawValue);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (_rawValue >= other._rawValue);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (_rawValue <= other._rawValue);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (_rawValue == other._rawValue);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (_rawValue != other._rawValue);
}

// Arith operators overloaded
// return (Fixed((*this).toFloat() + other.toFloat()));
Fixed Fixed::operator+(const Fixed &other)
{
	return (Fixed(toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other)
{
	return (Fixed(toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other)
{
	return (Fixed(toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other)
{
	return (Fixed(toFloat() / other.toFloat()));
}

// Inc/Dec operators overloaded

// pre-icrement
Fixed &Fixed::operator++(void)
{
	if (_rawValue == INT_MAX)
		std::cerr << "!!! Overflow (out of INT type range)" << std::endl;
	_rawValue++;
	return (*this);
}

// post-increment
// int parameter indicates that the function is the post-increment version of the operator.
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this); // save a copy
	operator++();     // pre-increm
	return (tmp);
}

// pre-decrem
Fixed &Fixed::operator--(void)
{
	if (_rawValue == INT_MIN)
		std::cerr << "!!! Overflow (out of INT type range)" << std::endl;
	_rawValue--;
	return (*this);
}

// post-decrem
Fixed Fixed::operator--(int)
{
	Fixed tmp(*this); // save a copy
	operator--();     // pre-increm
	return (tmp);
}

// min / max
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	std::cout << "Max called" <<std::endl;	
	return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	std::cout << "Const max called" <<std::endl;	
	return (a > b ? a : b);
}
