/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 02:22:21 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/25 04:11:08 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <exception>
# include <iterator>
# include <algorithm>
# include <set>

class Span
{
    private:
        unsigned int _N;
        std::vector<int> _vec;
        // std::vector<int>::iterator it;
        
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();
        //
        void addNumber(int k);
        void addNumber(std::vector<int>::iterator it_first, std::vector<int>::iterator it_last);
        long long shortestSpan(void);
        long long longestSpan(void);        
        //
        class FullException : public std::exception
        {
            virtual const char* what() const throw(); 
        };        
        class NoSpanException : public std::exception
        {
            virtual const char* what() const throw();
        };
        class TooManyException : public std::exception
        {
            virtual const char* what() const throw(); 
        };        
};



#endif 

