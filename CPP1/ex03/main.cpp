/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:21:35 by caguillo          #+#    #+#             */
/*   Updated: 2024/10/29 01:57:06 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
	// case A the ref is done/initialize inside the constructor
	{
		Weapon club = Weapon("crude spiked club"); // or Weapon club("crude spiked club");
		HumanA bob("Bob", club); //Weapon& _weaponA = club = "crude..." // initialize the ref var
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}

	// case B, no ref, so no init, and need a pointer
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		// jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
		
		// // to check
		// std::cout << &club << std::endl;
		// std::cout << jim.getWeapon() << std::endl;
	}
		
	return (0);
}