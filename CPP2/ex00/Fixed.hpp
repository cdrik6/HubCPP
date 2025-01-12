/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:12:03 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/03 22:12:24 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
  private:
	int _rawBits;
	static const int _frBits = 8;

  public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();	
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif

// NB static and const together ?
// static: Indicates that _fbit belongs to the class itself rather than to any specific instance of the class.
// This means that all instances of the class will share the same _fbit value,
// and it doesn’t take up space in each instance’s memory.

// Using static const for class constants is common because:
// It saves memory by storing the constant once, not in every instance.
// It provides a single point of change if the constant value needs to be modified later.
// It’s easy to access in other class methods, similar to a global constant but scoped to the class.