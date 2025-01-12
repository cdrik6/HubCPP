/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 03:57:08 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/17 01:36:16 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Default Dog constructed" << std::endl;    
}

Dog::Dog(const Dog& other) : Animal(other)
{
    if (this == &other)
    {
        std::cerr << "Error: Self-copying during construction is undefined." << std::endl;
        return;
    }
    std::cout << "Dog copy constructor of type " << other._type << std::endl;
    *this = other;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this == &other)
        return (*this);
    _type = other._type;
    return(*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructed" << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << "Woof" << std::endl;
}
