/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 04:58:23 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/19 04:31:06 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource()
{
    std::cout << "Default MateriaSource constructed" << std::endl;
    for (int i = 0; i < SLOTS; i++)
        _materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < SLOTS; i++)
        _materia[i] = NULL;
    if (this == &other)
    {
        std::cerr << "Error: Self-copying during construction is undefined" << std::endl;        
        return;
    }
    *this = other;
    std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this == &other)
        return (*this);
    for (int i = 0; i < SLOTS; i++)
    {
        delete _materia[i];
        _materia[i] = NULL;
        if (other._materia[i])        
            _materia[i] = (*other._materia[i]).clone();
    }        
    std::cout << "MateriaSource copy assignment operator called" << std::endl;
    return (*this);
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructed" << std::endl;
    for (int i = 0; i < SLOTS; i++)
    {
        if (_materia[i])
            std::cout << "MateriaSource(" << i << ") " << (*_materia[i]).getType() <<" deleted" << std::endl;
        delete _materia[i];        
        _materia[i] = NULL;        
    }        
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (!m)
    {
        std::cout << "Can't learn from an inexistant materia" << std::endl;
        return ;
    }        
    for (int i = 0; i < SLOTS; i++)
    {        
        if (_materia[i] == NULL)
        {
            _materia[i] = m;
            std::cout << "Materia " << (*m).getType() << " stored" << std::endl;
            return ;
        }            
    }
    std::cout << "Full, can't store more materia" << std::endl;
    delete m;    
}

AMateria *MateriaSource::createMateria(std::string const& type)
{
    for (int i = 0; i < SLOTS; i++)
    {        
        if (_materia[i] && (*_materia[i]).getType() == type)
        {
            std::cout << "Materia " << type << " created" << std::endl;
            return ((*_materia[i]).clone());
        }        
    }
    std::cout << "No Materia created" << std::endl;
    return (NULL);
}

