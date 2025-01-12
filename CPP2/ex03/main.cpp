/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:21:35 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/08 00:47:16 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(int argc, char **argv)
{
	
	(void)argv;
	if (argc > 1)	
	{
		std::cerr << "Usage: ./bsp (no argument)" << std::endl;
		return (1);
	}
	Point a(0,0), b(4,6), c(5,0);
	Point p(2,2);
	Point m(4,10);
	Point n(2,4);
	Point l(4,5.999); // rawValue = 1536 => 6.000 
	Point r(4,5.998); // rawValue = 1535 => 5.996 
	Point s(-2.001,2.002);		
	
	std::cout << "P(" << p.get_x() << "," << p.get_y() << ") : ";
	if (bsp(a, b, c, p))
		std::cout << "Inside" << std::endl;
	else	
		std::cout << "Not Inside" << std::endl;
	std::cout << "P(" << m.get_x() << "," << m.get_y() << ") : ";
	if (bsp(a, b, c, m))
		std::cout << "Inside" << std::endl;
	else
		std::cout << "Not Inside" << std::endl;
	std::cout << "P(" << n.get_x() << "," << n.get_y() << ") : ";
	if (bsp(a, b, c, n))
		std::cout << "Inside" << std::endl;
	else
		std::cout << "Not Inside" << std::endl;		
	std::cout << "P(" << l.get_x() << "," << l.get_y() << ") : ";
	if (bsp(a, b, c, l))
		std::cout << "Inside" << std::endl;
	else
		std::cout << "Not Inside" << std::endl;		
	std::cout << "P(" << r.get_x() << "," << r.get_y() << ") : ";
	if (bsp(a, b, c, r))
		std::cout << "Inside" << std::endl;
	else
		std::cout << "Not Inside" << std::endl;	
	std::cout << "P(" << s.get_x() << "," << s.get_y() << ") : ";
	if (bsp(a, b, c, s))
		std::cout << "Inside" << std::endl;
	else
		std::cout << "Not Inside" << std::endl;
	// // limit	
	// Point t(-8388608,8388607);	
	// std::cout << "P(" << t.get_x() << "," << t.get_y() << ") : ";
	// if (bsp(a, b, c, t))
	// 	std::cout << "Inside" << std::endl;
	// else
	// 	std::cout << "Not Inside" << std::endl;
	// //	
	// Point u(-8388609,8388609);
	// std::cout << "P(" << u.get_x() << "," << u.get_y() << ") : ";
	// if (bsp(a, b, c, u))
	// 	std::cout << "Inside" << std::endl;
	// else
	// 	std::cout << "Not Inside" << std::endl;	
			
	return (0);
}
