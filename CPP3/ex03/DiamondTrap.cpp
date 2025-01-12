/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 03:11:29 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/11 20:42:19 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

// Default constructor
DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap()
{
	
	_name = "default";
	ClapTrap::_name = _name +  "_clap_name";	
	// _hit = FragTrap::_hit;
	// _energy = ScavTrap::_energy;
	// _damage = FragTrap::_damage;		
	_energy = 50;
	std::cout << "Default DiamondTrap constructor called" << std::endl;
}

// Parametric constructor
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	_name = name;
	ClapTrap::_name = _name +  "_clap_name";	
	// _hit = FragTrap::_hit;
	// _energy = ScavTrap::_energy;
	// _damage = FragTrap::_damage;	
	_energy = 50;	
	std::cout << "DiamondTrap " << _name << " constructed" << std::endl;
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "DiamondTrap copy constructor of " << other._name << std::endl;
	*this = other;	
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	_name = other._name;
	_hit = other._hit;
	_energy = other._energy;
	_damage = other._damage;
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << _name << " destructed" << std::endl;
}

//
void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "My name is " << _name << std::endl;
	std::cout << "My ClapTrap name is " << ClapTrap::_name << std::endl;
}