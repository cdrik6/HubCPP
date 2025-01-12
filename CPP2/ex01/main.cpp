/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:21:35 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/08 00:52:18 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	
	a = Fixed( 1234.4321f );	
	std::cout << std::endl;
	
	// << as function --> <<("a is ") string arg, <<(a) fixed arg, <<(std::endl);
	
	// same as .toFloat below due to def of <<(a)
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;	
	std::cout << std::endl;
		
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;	
	std::cout << std::endl;
	
	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "b is " << b.toFloat() << " as float" << std::endl;
	std::cout << "c is " << c.toFloat() << " as float" << std::endl;
	std::cout << "d is " << d.toFloat() << " as float" << std::endl;
	std::cout << std::endl;
	
	
	// 42.4219 output but it is well 42.421875 stored in float
	float f = 42.421875;
	std::cout << "f = " << f << std::endl;	
	if (f < 42.421876)
		std::cout << "f is below 42.421876" << std::endl;
	std::cout << std::endl;	

	// in fixed(256) 0.002 = 0.005 because same rawValue = 1, so in float 0.00390625
	Fixed const e(0.002f);	
	std::cout << "e  = 0.002f " << std::endl;
	std::cout << "e is " << e.toFloat() << " as float" << std::endl;
	std::cout << std::endl;	
	Fixed const g(0.005f);
	std::cout << "g  = 0.005f " << std::endl;	
	std::cout << "g is " << g.toFloat() << " as float" << std::endl;
	std::cout << std::endl;
	// in fixed(256) precision or step is in 1/256 = 0.0039, so 4 elements de +0.001
	// 0.002 = 0.003 = 0.004 = 0.005 ou 0.346 = 0.347 = 0.348 = 0.349
		
	// in fixed 0.001 stores as 0 in rawValue, h therefore = 0 en float --> precision lost
	Fixed const h(0.001f);
	std::cout << "h  = 0.001f " << std::endl;	
	std::cout << "h is " << h << std::endl;
	std::cout << "h is " << h.toInt() << " as integer" << std::endl;
	std::cout << "h is " << h.toFloat() << " as float" << std::endl;
	std::cout << std::endl;

	// // int limits
	// Fixed const i(-8388608);
	// std::cout << "i is " << i << std::endl;
	// std::cout << "i is " << i.toInt() << " as integer" << std::endl;
	// std::cout << "i is " << i.toFloat() << " as float" << std::endl;
	// std::cout << std::endl;
	// Fixed const j(-8388609);
	// std::cout << "j is " << j << std::endl;
	// std::cout << "j is " << j.toInt() << " as integer" << std::endl;
	// std::cout << "j is " << j.toFloat() << " as float" << std::endl;
	// std::cout << std::endl;
	// // float limits
	// Fixed const k(-8388608.0f);
	// std::cout << "k is " << k << std::endl;
	// std::cout << "k is " << k.toInt() << " as integer" << std::endl;
	// std::cout << "k is " << k.toFloat() << " as float" << std::endl;
	// std::cout << std::endl;
	// Fixed const l(-8388609.0f);
	// std::cout << "l is " << l << std::endl;
	// std::cout << "l is " << l.toInt() << " as integer" << std::endl;
	// std::cout << "l is " << l.toFloat() << " as float" << std::endl;
	// std::cout << std::endl;
	
	return (0);
}

/* draft */

// std::cout << roundf(0.5f) << std::endl;

// Fixed e;
// e = Fixed( 0.999f );
// std::cout << "e is " << e << std::endl;
// std::cout << "e is " << e.toInt() << " as integer" << std::endl;
// std::cout << "e is " << e.toFloat() << " as float" << std::endl;
// std::cout << std::endl;