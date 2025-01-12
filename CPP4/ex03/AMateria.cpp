/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 00:59:53 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/20 03:17:59 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"


AMateria::AMateria()
{
    std::cout << "Default AMateria constructed" << std::endl;
    _type = "Default";
}

AMateria::AMateria(std::string const& type)
{
    std::cout << "AMateria " << type << " constructed" << std::endl;
    _type = type;
}

AMateria::AMateria(const AMateria& other)
{
    if (this == &other)
        _type = "Default";    
    *this = other;
    std::cout << "AMateria copy constructor of type " << _type << std::endl;    
}

AMateria& AMateria::operator=(const AMateria& other)
{
    std::cout << "AMateria copy assignment operator called" << std::endl;
    if (this == &other)
        return (*this);
    _type = other._type;
    return(*this);
}

AMateria::~AMateria()
{
    std::cout << "AMateria " << _type << " destructed" << std::endl;
}

std::string const& AMateria::getType() const
{
    return (_type);
}

void AMateria::use(ICharacter &target)
{
    std::cout << "Default use at " << target.getName() << std::endl;
}