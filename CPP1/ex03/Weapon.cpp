/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:26:14 by caguillo          #+#    #+#             */
/*   Updated: 2024/10/29 01:56:42 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string initType)
{
	_type = initType;
}

Weapon::~Weapon()
{
}

void Weapon::setType(std::string newType)
{
	_type = newType;
}

const std::string &Weapon::getType(void)
{
	return (_type);
}
