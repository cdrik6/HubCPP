/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 05:01:24 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/11 04:50:27 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Canonicals
FragTrap::FragTrap(void) : ClapTrap()
{
    _name = "default FragTrap";
    _hit = 100;
    _energy = 100;
    _damage = 30;
    std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _name = name;
    _hit = 100;
    _energy = 100;
    _damage = 30;
	std::cout << "FragTrap " << _name << " constructed" << std::endl;
}


FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor of " << other._name << std::endl;
	*this = other;    
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	_name = other._name;
	_hit = other._hit;
	_energy = other._energy;
	_damage = other._damage;
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << _name << " destructed" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (_hit == 0)
		std::cout << "FragTrap " << _name << " is dead, can't attack " << target << std::endl;
	else if (_energy == 0)
		std::cout << "FragTrap " << _name << " is tired, can't attack " << target << std::endl;
	else
	{
		_energy = _energy - 1;
		std::cout << "FragTrap " << _name << " attacks " << target;
		std::cout << ", causing " << _damage << " points of damage!" << std::endl;
	}	
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " is requesting a positive high fives" << std::endl;
}