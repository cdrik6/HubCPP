/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:40:49 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/16 05:27:49 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <exception>
# include <limits>
# include <cstdlib>
# include <iomanip>
# include <cerrno>
# include <cmath>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const& other);
		ScalarConverter& operator=(ScalarConverter const& other);
		~ScalarConverter();
	public:
		static void convert(std::string str);
		//
		class Invalid: public std::exception
    	{
			public:
				virtual const char* what() const throw(); 
		};	
		class OutOfRange: public std::exception
    	{
			public:
				virtual const char* what() const throw(); 
		};
};

int is_inf(std::string str);
bool is_nan(std::string str);
bool is_char(std::string str);
bool is_displayable(char c);
int count_pt(std::string str);
std::string get_type(std::string str);

#endif

// NB:
// convert is a static member function --> it can be called directly on the class
// i.e.: ScalarConverter::convert("value"); without requiring an object of the class.
