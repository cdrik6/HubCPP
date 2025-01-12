/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 05:04:56 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/24 01:32:54 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

NotFoundException::NotFoundException(const int& k) : _k(k)
{
    std::ostringstream oss;
    oss << _k;
    _error = "Occurence " + oss.str() + " not found";
}

const char* NotFoundException::what() const throw()
{
    return (_error.c_str());
    // return ("Occurence not found");
}

template <typename T>
typename T::iterator easyfind(T& container, int k)
{    
    typename T::iterator it; //"un iterator de type T pas un iterator de T --> typename"
    
    it = std::find(container.begin(), container.end(), k);   
    if (it == container.end())    
        throw (NotFoundException(k));    
    return (it);
}

// NB
// T::iterator it; // Error: The compiler doesn't know if T::iterator is a type or not
// Without typename (T::iterator it;), the compiler is unsure whether T::iterator refers 
// to a "variable" or a "type." Adding typename disambiguates it.