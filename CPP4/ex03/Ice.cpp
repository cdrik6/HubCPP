/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 02:57:21 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/20 03:18:40 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Default ice constructed" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other)
{
    if (this == &other)
    {
        std::cerr << "Error: Self-copying during construction is undefined" << std::endl;
        return;
    }    
    *this = other;
    std::cout << "Ice copy constructor of type " << other._type << std::endl;
}

Ice &Ice::operator=(const Ice& other)
{    
    std::cout << "Ice copy assignment operator called" << std::endl;
    if (this == &other)
        return (*this);
    _type = other._type;    
    return (*this);
}   

Ice::~Ice()
{
    std::cout << "Ice destructed" << std::endl;
}

AMateria    *Ice::clone(void) const
{
    std::cout << "Clone of Ice" << std::endl;
    return (new Ice(*this));
}

void    Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}