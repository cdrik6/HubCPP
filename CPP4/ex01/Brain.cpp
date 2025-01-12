/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:27:01 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/17 00:08:17 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp" 

Brain::Brain()
{
    std::string id = "";        
    
    for (int i = 0; i < ID_NBR; i++)
    {
        // id.push_back( i % 26 + 97);
        id.push_back(rand() % 26 + 97);
        _ideas[i] = id; // "an idea"             
    }
    std::cout << "Default Brain constructed" << std::endl;
    std::cout << "7th idea: " << _ideas[6] << std::endl; // to test deep copy
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain copy constructed" << std::endl;
    if (this == &other)
        for (int i = 0; i < ID_NBR; i++)
            _ideas[i] = "an idea";
    *this = other;
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain copy assignment operator called" << std::endl;    
    if (this == &other)
        return(*this);
    for (int i = 0; i < ID_NBR; i++)    
        _ideas[i] = other._ideas[i];
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructed" << std::endl;    
}

std::string Brain::get_ideas(int i) const
{
    if (0 <= i && i < ID_NBR)
        return(_ideas[i]);
    else
        return("No idea");
}

void Brain::set_ideas(int i, std::string deepIdea)
{
    if (0 <= i && i < ID_NBR)
        _ideas[i] = deepIdea;
}
