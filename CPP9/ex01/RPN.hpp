/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 05:40:33 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/30 23:59:56 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <cerrno>
# include <cstdlib>
# include <iostream>
# include <stack>
# include <string>
# include <sstream>
# include <cmath>
# include <stdexcept>
# include <limits>

# define OK 1
# define KO 0

double evaluation(std::string expr);
int is_operand(std::string token, double *d);
int is_operator(std::string token);
double compute(double d1, double d2, std::string token);
double check_add(double d1, double d2);
double check_sub(double d1, double d2);
double check_mul(double d1, double d2);
double check_div(double d1, double d2);

class InputException : public std::exception
{
    virtual const char* what() const throw();
};


#endif