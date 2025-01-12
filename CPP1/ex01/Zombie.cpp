/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:20:25 by caguillo          #+#    #+#             */
/*   Updated: 2024/10/27 04:36:48 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Default Constructor
Zombie::Zombie(void)
{
	std::cout << "Default constructor" << std::endl;
}

// Constructor overloaded
Zombie::Zombie(std::string name)
{
	_name = name;
	std::cout << _name << " constructed" << std::endl;
}

// Destructor
Zombie::~Zombie(void)
{
	std::cout << _name << " destroyed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	_name = name;
}
