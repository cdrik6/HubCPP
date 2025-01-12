/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:21:35 by caguillo          #+#    #+#             */
/*   Updated: 2024/10/27 02:25:07 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*z;
	
	// Stack
	randomChump("zombie_stack");
	std::cout << std::endl;
	
	// Heap
	z = newZombie("zombie_heap");
	(*z).announce();
	delete	z;
	
	// Zombie toto("toto");
	// toto.announce();
	return (0);
}
