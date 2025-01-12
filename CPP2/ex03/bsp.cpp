/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 03:31:41 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/06 23:01:14 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// S = 1/2||AB^AC|| = 1/2 det(AB, AC)
float	area(Point const a, Point const b, Point const c)
{
	return (0.5 * fabs((b.get_x().toFloat() - a.get_x().toFloat())
			* (c.get_y().toFloat() - a.get_y().toFloat()) - (b.get_y().toFloat()
				- a.get_y().toFloat()) * (c.get_x().toFloat()
				- a.get_x().toFloat())));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	aABC;
	float	aPAB;
	float	aPAC;
	float	aPBC;

	aABC = area(a, b, c);
	aPAB = area(point, a, b);
	aPAC = area(point, a, c);
	aPBC = area(point, b, c);
	// std::cout << "aABC = " << aABC << std::endl;
	// std::cout << "aPAB = " << aPAB << std::endl;
	// std::cout << "aPAC = " << aPAC << std::endl;
	// std::cout << "aPBC = " << aPBC << std::endl;
	if ((aABC == aPAB + aPAC + aPBC) && (aPAB > 0) && (aPAC > 0) && (aPBC > 0))
		return (true);
	return (false);
}

/* draft*/
// int tmp;
// tmp = abs((b.get_x().getRawBits() - a.get_x().getRawBits())
// 		* (c.get_y().getRawBits() - a.get_y().getRawBits())
// 		- (b.get_y().getRawBits() - a.get_y().getRawBits())
// 		* (c.get_x().getRawBits() - a.get_x().getRawBits()));
// Fixed ar(tmp);
// return (0.5*ar.toFloat());
