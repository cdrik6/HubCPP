/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:38:22 by caguillo          #+#    #+#             */
/*   Updated: 2024/10/29 01:43:40 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string nameB) : _nameB(nameB), _weaponB(NULL)
{	
}

HumanB::~HumanB()
{
}

void HumanB::attack(void)
{
	if (!_weaponB)
		std::cerr << _nameB << " can't attack (no weapon)" << std::endl;
	else
		std::cout << _nameB << " attacks with their " << (*_weaponB).getType() << std::endl;
}

//*** case 1 --> not the address of the weapon sent, but an address of a copy ***//
// void HumanB::setWeapon(Weapon weapon)
// {
// 	_weaponB = weapon;
// 	std::cout << "set weapon no ref" << &weapon << std::endl;
// }
// GPT confirms it:
// Here, weapon is passed by value, meaning a copy of the original Weapon object is made when calling the function.
// The _weaponB member is then set to the address of this copy.
// Since weapon is a local copy, it will go out of scope once the function returns,
// which means _weaponB will end up pointing to a dangling pointer (invalid memory),
// likely causing undefined behavior.


//*** case 2 --> get the original address of what is sent due to the reference ***//
void HumanB::setWeapon(Weapon& weapon)
{
	_weaponB = &weapon;
	// std::cout << "set weapon on ref" << &weapon << std::endl;
}
// GPT confirms it:
// Here, weapon is passed by reference. This means no copy is made;
// weapon refers directly to the original Weapon object passed in.
// _weaponB is set to the address of the original object.
// This is safer and more efficient because no copy is created,
// and _weaponB will point to a valid Weapon object as long as the original object exists.

//*** case 3 --> if _weaponB is init to NULL, will segfault, if not it seems work, but where does _weaponB point? ***//
// void HumanB::setWeapon(Weapon& weapon)
// {
// 	(*_weaponB) = weapon;
// 	// std::cout << "set weapon on ref by value" << &weapon << std::endl;
// }
// GPT confirms it:
// The expression (*_weaponB) = weapon; means it assigns the value of weapon to the object currently pointed to by _weaponB.
// This only works if _weaponB already points to a valid Weapon object.
// If _weaponB is nullptr or an invalid pointer, dereferencing it will lead to undefined behavior.


// // tool to check
// Weapon *HumanB::getWeapon(void)
// {
// 	return (_weaponB);
// }
