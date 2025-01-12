/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:21:35 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/08 00:24:00 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );	
	std::cout << std::endl;	
	//
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;	
	std::cout << std::endl;	
	//
	std::cout << a++ << std::endl; // post-increm, ouput a, then ++
	std::cout << a << std::endl; //a has been well ++ 
	std::cout << std::endl;	
	//
	std::cout << b << std::endl;
	std::cout << std::endl;	
	//
	std::cout << Fixed::max( a, b ) << std::endl; 
	// NB
	// a is a non-const Fixed and b is a const Fixed, neither overload exactly matches.
	// However, the const version will work, as it can accept both const and non-const objects
	// by treating a as a constant reference.
	std::cout << Fixed::max( b, b ) << std::endl; 
	std::cout << Fixed::max( a, a ) << std::endl; 
	std::cout << std::endl;
	//
	Fixed c( Fixed( 5.05f ) * Fixed( 5.05f ) / Fixed( 5.05f ));	
	std::cout << c << std::endl;
	std::cout << std::endl;
	//
	Fixed d( Fixed( 5.05f ) - Fixed( 5.05f ) + Fixed( 5.05f ));	
	std::cout << d << std::endl;
	std::cout << std::endl;
	//
	Fixed e( Fixed( 5.05f * 5.05f ) - Fixed( 5.05f ) * Fixed( 5.05f ));		
	std::cout << e << std::endl;	
	std::cout << std::endl;
	
	// inc a float vs inc a fixed
	float f = 5.05f;
	f++;
	std::cout << f << std::endl;
	//
	Fixed g(5.05f);	
	g++;
	std::cout << g << std::endl;
	//
	Fixed h(f);	
	h++;
	std::cout << h << std::endl;
	std::cout << std::endl;
	
	// // limit
	// Fixed i(8388607);
	// // i++;
	// // std::cout << i.toInt() << std::endl;		
	// int t = 0;
	// while(t < 256) // 255 ok 256 overflow
	// {
	// 	i++;
	// 	t++;
	// }
	// std::cout << i.toInt() << std::endl;		
	
	return (0);
}
