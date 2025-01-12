/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 04:04:50 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/17 02:01:22 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat")
{
    std::cout << "Default Cat constructed" << std::endl;
    _catBrain = new Brain();
}

// *this = other; --> delete issue: hasn't been constructed before, so can not delete as it is in the operator=
Cat::Cat(const Cat& other) : AAnimal(other)
{
    if (this == &other)
    {
        std::cerr << "Error: Self-copying during construction is undefined." << std::endl;
        return;
    }
    std::cout << "Cat copy constructor of type " << other._type << std::endl;        
    _type = other._type;    
    _catBrain = new Brain(*other._catBrain);       
}

// Has been constructed before, so need a delete
Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this == &other)
        return (*this);
    _type = other._type;
    delete _catBrain;
    _catBrain = new Brain(*other._catBrain);
    return(*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructed" << std::endl;
    delete _catBrain;
}

void Cat::makeSound(void) const
{
    std::cout << "Meow" << std::endl;
}

Brain& Cat::get_catBrain(void) const
{
   return(*_catBrain);
}
