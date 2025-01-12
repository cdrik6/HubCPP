/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 03:48:24 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/17 02:00:41 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    std::cout << "Default AAnimal constructed" << std::endl;
    _type = "Default AAnimal";
}

AAnimal::AAnimal(std::string type)
{
    _type = type;
    std::cout << "AAnimal " << _type << " constructed" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other)
{
    if (this == &other)
    {
        std::cerr << "Error: Self-copying during construction is undefined." << std::endl;
        return;
    }
    std::cout << "AAnimal copy constructor of type " << other._type << std::endl;
    *this = other;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
    std::cout << "AAnimal copy assignment operator called" << std::endl;
    if (this == &other)
        return (*this);
    _type = other._type;
    return(*this);
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal " << _type << " destructed" << std::endl;
}

std::string AAnimal::get_type(void) const
{
    return(_type);
}

// void AAnimal::makeSound(void) const
// {
//     std::cout << "Default AAnimal sound" << std::endl;
// }
