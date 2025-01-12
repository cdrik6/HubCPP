/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 04:47:55 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/26 04:51:21 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{    
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other)
{
    if (this == &other)
    {
        std::cerr << "Error: Self-copying during construction is undefined" << std::endl;        
        return ;
    }
    *this = other;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other)
{
    if (this == &other)
        return (this);
    (*this).c = other.c;
    return (this);    
}

template <typename T>
MutantStack<T>::~MutantStack()
{    
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
    return ((*this).c.begin()); // Access underlying container's begin()
}


template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
    return ((*this).c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin(void) const
{    
    return ((*this).c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end(void) const
{
    return ((*this).c.end());
}
