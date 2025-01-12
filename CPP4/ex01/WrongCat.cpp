/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 04:04:50 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/13 06:09:36 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "Default WrongCat constructed" << std::endl;    
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    if (this == &other)
    {
        std::cerr << "Error: Self-copying during construction is undefined." << std::endl;
        return;
    }
    std::cout << "WrongCat copy constructor of type " << other._type << std::endl;
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    if (this == &other)
        return (*this);
    _type = other._type;
    return(*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructed" << std::endl;
}

void WrongCat::makeSound(void) const
{
    std::cout << "Wrong Meow" << std::endl;
}
