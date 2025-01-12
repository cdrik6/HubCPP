/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 03:48:24 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/17 01:31:18 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Default Animal constructed" << std::endl;
    _type = "Default Animal";
}

Animal::Animal(std::string type)
{
    _type = type;
    std::cout << "Animal " << _type << " constructed" << std::endl;
}

Animal::Animal(const Animal& other)
{
    if (this == &other)
    {
        std::cerr << "Error: Self-copying during construction is undefined." << std::endl;
        return;
    }
    std::cout << "Animal copy constructor of type " << other._type << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this == &other)
        return (*this);
    _type = other._type;
    return(*this);
}

Animal::~Animal()
{
    std::cout << "Animal " << _type << " destructed" << std::endl;
}

std::string Animal::get_type(void) const
{
    return(_type);
}

void Animal::makeSound(void) const
{
    std::cout << "Default Animal sound" << std::endl;
}
