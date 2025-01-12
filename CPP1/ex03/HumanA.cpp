/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:37:51 by caguillo          #+#    #+#             */
/*   Updated: 2024/10/29 01:13:37 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string nameA, Weapon& weaponA) : _nameA(nameA), _weaponA(weaponA)
{	
}

// // be careful, writing below doesn't work, due to initialization of the variable by ref
// HumanA::HumanA(std::string nameA, Weapon& weaponA)
// {	
// 	 _weaponA = weaponA;
// 	 _nameA = nameA;	 
// }

HumanA::~HumanA()
{
}

void HumanA::attack(void)
{
	std::cout << _nameA << " attacks with their " << _weaponA.getType() << std::endl;
}
