/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 03:12:39 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/06 05:54:01 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
  private:
	const Fixed x;
	const Fixed y;

  public:
	Point();
	Point(const float a, const float b);
	Point(const Point& other);
	Point& operator=(const Point& other);
	~Point();
	const Fixed get_x(void) const;
	const Fixed get_y(void) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif