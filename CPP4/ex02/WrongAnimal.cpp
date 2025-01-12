/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 03:48:24 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/17 02:01:46 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "Default WrongAnimal constructed" << std::endl;
    _type = "Default WrongAnimal";
}

WrongAnimal::WrongAnimal(std::string type)
{
    _type = type;
    std::cout << "WrongAnimal " << _type << " constructed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    if (this == &other)
    {
        std::cerr << "Error: Self-copying during construction is undefined." << std::endl;
        return;
    }
    std::cout << "WrongAnimal copy constructor of type " << other._type << std::endl;
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    if (this == &other)
        return (*this);
    _type = other._type;
    return(*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal " << _type << " destructed" << std::endl;
}

std::string WrongAnimal::get_type(void) const
{
    return(_type);
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "Default WrongAnimal sound" << std::endl;
}
