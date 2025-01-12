/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 03:13:04 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/06 06:47:51 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{     
}

Point::Point(const float a, const float b) : x(a), y(b)
{        
}

Point::Point(const Point& other) : x(other.x), y(other.y)
{    
}

// not used 
Point& Point::operator=(const Point& rhs)
{
    // if (this == &rhs)
    //     return(*this);    
    // x = rhs.x; // not defined
    // y = rhs.y; // not defined
    // return(*this);    
    (void)rhs;    
    return(*this);
}

Point::~Point()
{    
}

const Fixed Point::get_x(void) const
{
    return(x);
}

const Fixed Point::get_y(void) const
{
    return(y);
}
