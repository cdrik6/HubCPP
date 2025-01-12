/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 03:11:29 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/11 06:13:25 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Canonicals
ClapTrap::ClapTrap(void) : _name("default"), _hit(10), _energy(10), _damage(0)
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit(10), _energy(10), _damage(0)
{
	std::cout << "ClapTrap " << _name << " constructed" << std::endl;	
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap copy constructor of " << other._name << std::endl;
	//std::cout << name << " constructed by copy of " << other._name << std::endl;
	*this = other;
	// _name = name;
	// _hit = other._hit;
	// _energy = other._energy;
	// _damage = other._damage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	_name = other._name;
	_hit = other._hit;
	_energy = other._energy;
	_damage = other._damage;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << _name << " destructed" << std::endl;
}

// Getters
std::string ClapTrap::get_name(void) const
{
	return (_name);
}

unsigned int ClapTrap::get_hit(void) const
{
	return (_hit);
}

unsigned int ClapTrap::get_energy(void) const
{
	return (_energy);
}

unsigned int ClapTrap::get_damage(void) const
{
	return (_damage);
}

// Setters
void ClapTrap::set_hit(unsigned int hit_points)
{
	// if (hit_points < 0)
	// 	std::cout << "Hit points must be positive" << std::endl;
	// else
	_hit = hit_points;
}

void ClapTrap::set_energy(unsigned int energy_points)
{
	// if (energy_points < 0)
	// 	std::cout << "Energy points must be positive" << std::endl;
	// else
	_energy = energy_points;
}

void ClapTrap::set_damage(unsigned int damage_points)
{
	// if (damage_points < 0)
	// 	std::cout << "Damage points must be positive" << std::endl;
	// else
	_damage = damage_points;
}

//
void ClapTrap::attack(const std::string &target)
{
	if (_hit == 0)
		std::cout << "ClapTrap " << _name << " is dead, can't attack " << target << std::endl;
	else if (_energy == 0)
		std::cout << "ClapTrap " << _name << " is tired, can't attack " << target << std::endl;
	else
	{
		_energy = _energy - 1;
		std::cout << "ClapTrap " << _name << " attacks " << target;
		std::cout << ", causing " << _damage << " points of damage!" << std::endl;
	}
	// std::cout << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit == 0)
		std::cout << "ClapTrap " << _name << " is already dead" << std::endl;
	else 
	{
		if (_hit > amount)
		{
			_hit = _hit - amount;
			std::cout << "ClapTrap " << _name << " has taken " << amount << " points of damage" << std::endl;
			std::cout << "ClapTrap " << _name << " health level: " << _hit << std::endl;
		}			
		else
		{
			_hit = 0;
			std::cout << "ClapTrap " << _name << " has taken " << amount << " points of damage" << std::endl; 
			std::cout << "ClapTrap " << _name << " is now dead" << std::endl;
		}		    
	}
	// std::cout << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit == 0)
		std::cout << "ClapTrap " << _name << " is dead, too late to be repaired" << std::endl;
	else if (_energy == 0)
		std::cout << "ClapTrap " << _name << " is too tired to be repaired" << std::endl;	
	else 
	{
		_hit = _hit + amount;
		_energy = _energy - 1;
		std::cout << "ClapTrap " << _name << " has been repaired by " << amount << " points" << std::endl;
		std::cout << "ClapTrap " << _name << " health level: " << _hit << std::endl;
	}
	// std::cout << std::endl;
}
