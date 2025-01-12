/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 04:17:39 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/24 01:36:41 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <exception>
# include <algorithm>

# include <sstream>
# include <string>

class NotFoundException : public std::exception
{
    private :
        const int& _k;
        std::string _error;        
    public :
       NotFoundException(const int& k);       
       virtual const char* what() const throw();       
};

template <typename T>
typename T::iterator easyfind(T& container, int k);

# include "easyfind.tpp"

#endif
