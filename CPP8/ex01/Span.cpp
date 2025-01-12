/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 02:37:48 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/25 04:24:37 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0)
{        
}

Span::Span(unsigned int N) : _N(N)
{    
}

Span::Span(const Span& other)
{
    if (this == &other)
    {
        std::cerr << "Error: Self-copying during construction is undefined" << std::endl;        
        return;
    }
    *this = other;
}

Span& Span::operator=(const Span& other)
{
    if (this == &other)
        return (*this);
    _vec.clear();
    _N = other._N;
    for (int i = 0; i < _N; i++)       
        _vec.push_back(other._vec[i]);
    return (*this);    
}

Span::~Span()
{    
}

const char* Span::FullException::what() const throw()
{
    return ("Full: can't add more number");
}

const char* Span::NoSpanException::what() const throw()
{
    return ("No Span, need at least 2 numbers");
}

const char* Span::TooManyException::what() const throw()
{
    return ("Too many numbers to add, range too big for the span size");
}

void Span::addNumber(int k)
{
    if (_vec.size() == _N)
        throw (FullException());
    _vec.push_back(k);
}

long long Span::longestSpan(void)
{
    if (_vec.size() < 2)
        throw (NoSpanException());    
    int min = *min_element(_vec.begin(), _vec.end());    
    int max = *max_element(_vec.begin(), _vec.end());
    return(static_cast<long long>(max) - static_cast<long long>(min));
} 

long long Span::shortestSpan(void)
{   
    if (_vec.size() < 2)
        throw (NoSpanException());    
    std::vector<int> tmp = _vec;
    std::sort(tmp.begin(), tmp.end());
    long long min = static_cast<long long>(tmp.at(1)) - static_cast<long long>(tmp.at(0));
    for (int i = 2; i < tmp.size(); i++)
    {        
        if (min > static_cast<long long>(tmp.at(i)) - static_cast<long long>(tmp.at(i - 1)))
            min = static_cast<long long>(tmp.at(i)) - static_cast<long long>(tmp.at(i - 1));
    }    
    return (min);
}

void Span::addNumber(std::vector<int>::iterator it_first, std::vector<int>::iterator it_last)
{
    int k = _vec.size();
    //std::cout << k << std::endl;    
    std::vector<int>::iterator it;    
    
    if (_vec.size() == _N)
        throw (FullException());
    for (it = it_first; it != it_last; ++it)
        k++;    
    if (k > _N)
        throw (TooManyException());        
    _vec.insert(_vec.end(), it_first, it_last);
}


// using Set:
// int Span::shortestSpan(void)
// {   
//     if (_vec.size() < 2)
//         throw (NoSpanException());    
//     std::set<int> tmp;
//     for (int i = 0; i < _N; i++)
//     {
//         for (int j = i + 1; j < _N; j++)        
//             tmp.insert(abs(_vec[i] - _vec[j]));        
//     }
//     // // output to check
//     // std::set<int>::iterator it;
//     // for (it = tmp.begin(); it != tmp.end(); ++it)
//     // {
//     //     std::cout << *it << " ";
//     // }
//     // std::cout << std::endl;
//     // //   
//     return (*tmp.begin());
// }