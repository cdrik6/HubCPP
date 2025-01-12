/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 05:56:16 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/20 02:39:17 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : ICharacter()
{
    std::cout << "Default Character constructed" << std::endl;
    _name = "Default";
    for (int i = 0; i < SLOTS; i++)
        _inventory[i] = NULL;
    _left = NULL;    
    _sizeLeft = 0;
}

Character::Character(std::string const& name) : ICharacter()
{
    _name = name;
    for (int i = 0; i < SLOTS; i++)
        _inventory[i] = NULL;
    std::cout << "Character " << _name << " constructed" << std::endl;    
    _left = NULL;    
    _sizeLeft = 0;
}

// *this = other; --> deep copy, delete issue if not initialized --> so init first
Character::Character(const Character& other)
{
    for (int i = 0; i < SLOTS; i++)
        _inventory[i] = NULL;
    _left = NULL;
    _sizeLeft = 0;
    if (this == &other)
    {
        std::cerr << "Error: Self-copying during construction is undefined" << std::endl;
        return;
    }    
    *this = other;    
    std::cout << "Character copy constructor of " << other._name << std::endl;
}

Character& Character::operator=(const Character& other)
{
    std::cout << "Character copy assignment operator called" << std::endl;
    if (this == &other)
        return(*this);
    _name = other._name;    
    for (int i = 0; i < SLOTS; i++)
    {        
        delete _inventory[i]; // if (_inventory[i]) --> no need to check in c++ std
        _inventory[i] = NULL;    
        if (other._inventory[i])
            _inventory[i] = (*other._inventory[i]).clone();
    }    
    if (_sizeLeft > 0)
    {
        for (int i = 0; i < _sizeLeft; i++)
        {
            delete _left[i];
            _left[i] = NULL;
        }    
        delete[] _left;
        _left = NULL;               
    }        
    _sizeLeft = other._sizeLeft;
    if (_sizeLeft > 0)
    {
        _left = new AMateria*[_sizeLeft];
        for (int i = 0; i < _sizeLeft; i++)    
            _left[i] = other._left[i];      
    }    
    return(*this);
}

Character::~Character()
{
    std::cout << "Character " << _name << " destructed" << std::endl;
    for (int i = 0; i < SLOTS; i++)
    {   
        if (_inventory[i])     
            std::cout << "Inventory(" << i << ") " << (*_inventory[i]).getType() <<" deleted" << std::endl;
        delete _inventory[i]; // if (_inventory[i]) --> no need to check in c++ std
        _inventory[i] = NULL;
    }    
    for (int i = 0; i < _sizeLeft; i++)
    {
        delete _left[i];
        _left[i] = NULL;
    }    
    delete[] _left;
    _left = NULL;    
}

std::string const& Character::getName() const
{
    return(_name);
}

void Character::equip(AMateria *m)
{
    if (!m)
    {
        std::cout << "Equip failed, this materia doesn't exist" << std::endl;
        return ;
    }        
    for (int i = 0; i < SLOTS; i++)
    {        
        if (_inventory[i] == NULL)
        {
            _inventory[i] = m;
            std::cout << _name << " equipped with " << (*m).getType() << std::endl;
            return ;
        }            
    }
    std::cout << "Inventory full, " << _name << " can't get more materia" << std::endl;
    delete m;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= SLOTS)
    {
        std::cout << "Invalid index to unequip" << std::endl;
        return ;    
    }
    if (_inventory[idx] == NULL)
    {
        std::cout << "No materia to unequip" << std::endl;
        return ;    
    } 
    // std::cout << "1 - " << _inventory[idx] << std::endl;
    updateLeft(_inventory[idx]);    
    std::cout << _name << " unequipped of " <<  (*_inventory[idx]).getType() << std::endl;
    _inventory[idx] = NULL;
    // std::cout << "2 - " << _left[_sizeLeft - 1] << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= SLOTS)
    {
        std::cout << "Invalid index to use materia" << std::endl;
        return ;    
    }
    if (_inventory[idx] == NULL)
    {
        std::cout << "No materia to use" << std::endl;
        return ;    
    }
    (*_inventory[idx]).use(target);
}

void Character::updateLeft(AMateria* m)
{
    AMateria **tmp = _left; // save address memory    
        
    _sizeLeft++;        
    _left = new AMateria*[_sizeLeft]; // new address memory, do not affect old one now in tmp
    for (int i = 0; i < _sizeLeft - 1; i++)    
        _left[i] = tmp[i];    
    _left[_sizeLeft - 1] = m;            
    delete[] tmp; // needed as points to a memory that was allocated by new    
    // no need to delete tmp[i] as it is delete via _left[i] at destruction
}

/* draft */

// void Character::updateLeft(AMateria* m)
// {
//     AMateria **tmp = NULL;
    
//     std::cout << _sizeLeft << std::endl;
//     // tmp
//     if (_sizeLeft > 0)
//     {        
//         tmp = new AMateria*[_sizeLeft];
//         for (int i = 0; i < _sizeLeft; i++)    
//             tmp[i] = _left[i];
//     }
//     // // clean _left
//     // for (int i = 0; i < _sizeLeft; i++)
//     // {       
//     //     delete _left[i];
//     //     _left[i] = NULL;
//     // }    
//     // delete[] _left;
//     // _left = NULL;    
//     // update
//     _sizeLeft++;        
//     _left = new AMateria*[_sizeLeft];
//     for (int i = 0; i < _sizeLeft - 1; i++)    
//         _left[i] = tmp[i];    
//     _left[_sizeLeft - 1] = m;    
//     // // clean tmp
//     // std::cout << "titi = " << _sizeLeft << std::endl;
//     // for (int i = 0; i < _sizeLeft - 1; i++)
//     // {
//     //     std::cout << "i = " << i << std::endl;    
//     //     std::cout << tmp[i] << std::endl;    
//     //     delete tmp[i];
//     //     std::cout << "i = " << i << std::endl;    
//     //     tmp[i] = NULL;
//     // }
//     // std::cout << "toto" << std::endl;        
//     // delete[] tmp;
//     // tmp = NULL;
// }

/* before delete, is it really from a new ? */

// //std::cout << "ici" << std::endl;
// /******************recup adresse de ??? */
// std::cout << "1 - " << _inventory[idx] << std::endl;
// std::cout << "2 - " << _inventory[idx] << std::endl;

// std::cout << "ici" << std::endl;
// std::cout << _sizeLeft << std::endl;
// std::cout << "3 - " << m << std::endl; 

// virtual int getSize() const = 0;
// virtual int getSize() const;
// int Character::getSize() const
// {
//     return(_sizeLeft);
// }
