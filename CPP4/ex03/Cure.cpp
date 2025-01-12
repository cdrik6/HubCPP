/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 02:57:21 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/20 03:18:53 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Default cure constructed" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other)
{
    if (this == &other)
    {
        std::cerr << "Error: Self-copying during construction is undefined" << std::endl;
        return;
    }    
    *this = other;
    std::cout << "Cure copy constructor of type " << other._type << std::endl;
}

Cure &Cure::operator=(const Cure& other)
{    
    std::cout << "Cure copy assignment operator called" << std::endl;
    if (this == &other)
        return (*this);
    _type = other._type;    
    return (*this);
}   

Cure::~Cure()
{
    std::cout << "Cure destructed" << std::endl;
}

AMateria    *Cure::clone(void) const
{
    std::cout << "Clone of Cure" << std::endl;
    return (new Cure(*this));
}

void    Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}