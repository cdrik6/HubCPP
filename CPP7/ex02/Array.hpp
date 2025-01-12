/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 23:16:45 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/20 04:00:00 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T>
class Array
{
      private:
        T *_array;
        unsigned int _size;
        
      public:
        Array();
        Array(unsigned int n);
        Array(const Array<T>& other);
        Array<T>& operator=(const Array<T>& other);
        ~Array();
        //        
        const T& operator[](int i) const; // for read-only access
        T& operator[](int i); // for mutable access
        unsigned int size(void) const;
};

# include "Array.tpp"

#endif