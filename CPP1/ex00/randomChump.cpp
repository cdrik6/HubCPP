/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 02:00:07 by caguillo          #+#    #+#             */
/*   Updated: 2024/10/27 02:28:47 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie z(name);
    
	z.announce();
}

// Attention
// Zombie	z;
// z = Zombie(name);
// appelle le default constructor
// appelle le constructor overloaded
// et donc appelle 2 fois le destructor !!
