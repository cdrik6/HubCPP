/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 23:15:47 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/20 04:09:01 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{    
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    _array = new T[n];
    _size = n;
}
// NOT: _array = new Array<T>[n];
// otherwise it will be a tab of class Array<T>, we just want a tab of T

template <typename T>
Array<T>::Array(const Array<T>& other)
{
    if (this == &other)
    {
        std::cerr << "Error: Self-copying during construction is undefined" << std::endl;
        _array = NULL;
        _size = 0;
        return;
    }    
    _size = other._size;
    _array = new T[_size];
    for (int i = 0; i < _size; i++)    
        _array[i] = other._array[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (this == &other)
        return (*this);
    delete [] _array;
    _size = other._size;
    _array = new T[_size];
    for (int i = 0; i < _size; i++)    
        _array[i] = other._array[i];    
    return (*this);
}

template <typename T>
Array<T>::~Array()
{
    delete [] _array;   
}

template <typename T>
const T& Array<T>::operator[](int i) const
{
    if (i < 0 || i >= _size)
        throw (std::exception());
    return (_array[i]);
}

template <typename T>
T& Array<T>::operator[](int i)
{
    if (i < 0 || i >= _size)
        throw (std::exception());
        //throw (std::out_of_range("Error: out of range"));
    return (_array[i]);
}

template <typename T>
unsigned int Array<T>::size(void) const
{
    return (_size);
}
