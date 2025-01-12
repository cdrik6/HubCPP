/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 03:57:08 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/17 02:01:34 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog")
{
    std::cout << "Default Dog constructed" << std::endl; 
    _dogBrain = new Brain();
}

Dog::Dog(const Dog& other) : AAnimal(other)
{
    if (this == &other)
    {
        std::cerr << "Error: Self-copying during construction is undefined." << std::endl;
        return;
    }
    std::cout << "Dog copy constructor of type " << other._type << std::endl;    
    _type = other._type;
    _dogBrain = new Brain(*other._dogBrain);    
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this == &other)
        return (*this);
    _type = other._type;
    delete _dogBrain;
    _dogBrain = new Brain(*other._dogBrain);    
    return(*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructed" << std::endl;
    delete _dogBrain;
}

void Dog::makeSound(void) const
{
    std::cout << "Woof" << std::endl;
}

Brain& Dog::get_dogBrain(void) const
{
   return(*_dogBrain);
}
