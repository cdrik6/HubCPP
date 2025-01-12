/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 05:01:24 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/11 04:50:48 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Canonicals
ScavTrap::ScavTrap(void) : ClapTrap()
{
    _name = "default ScavTrap";
    _hit = 100;
    _energy = 50;
    _damage = 20;
    std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _name = name;
    _hit = 100;
    _energy = 50;
    _damage = 20;
	std::cout << "ScavTrap " << _name << " constructed" << std::endl;
}


ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor of " << other._name << std::endl;
	*this = other;    
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	_name = other._name;
	_hit = other._hit;
	_energy = other._energy;
	_damage = other._damage;
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << _name << " destructed" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (_hit == 0)
		std::cout << "ScavTrap " << _name << " is dead, can't attack " << target << std::endl;
	else if (_energy == 0)
		std::cout << "ScavTrap " << _name << " is tired, can't attack " << target << std::endl;
	else
	{
		_energy = _energy - 1;
		std::cout << "ScavTrap " << _name << " attacks " << target;
		std::cout << ", causing " << _damage << " points of damage!" << std::endl;
	}	
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}