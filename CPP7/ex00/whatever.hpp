/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:05:53 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/19 23:11:44 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <iomanip>

template<typename T>
void swap(T& a, T& b)
{
    T temp;

    temp = b;
    b = a;
    a = temp;
}

template<typename T>
T const & min(T const& a, T const& b)
{
    return (a < b ? a : b);
}

template<typename T>
T const & max(T const& a, T const& b)
{
    return (a > b ? a : b);
}

#endif
