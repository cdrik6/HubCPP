/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 02:13:10 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/16 05:48:13 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

const char* ScalarConverter::Invalid::what() const throw()
{
    return ("Input is not a valid number or character");
}

const char* ScalarConverter::OutOfRange::what() const throw()
{
    return ("Out of range");
}

int is_inf(std::string str)
{
	std::string inf[6] = {"inf", "+inf", "inff", "+inff", "-inf", "-inff"};

	for (int k = 0; k < 4; k++)
	{
		if (str == inf[k])		
			return (1);
	}
	for (int k = 4; k < 6; k++)
	{
		if (str == inf[k])		
			return (-1);
	}
	return (0);	
}

bool is_nan(std::string str)
{
	std::string nan[7] = {"nanf", "nan", "NaNf", "NaN", "NaNF", "NANF", "NAN"};

	for (int k = 0; k < 7; k++)
	{
		if (str == nan[k])		
			return (true);
	}
	return (false);	
}

bool is_char(std::string str)
{
	if (str.length() == 1 && !std::isdigit(str.at(0)))	
			return (true);
	return (false);	
}

bool is_displayable(char c)
{
	return (std::isprint(static_cast<unsigned char>(c)));
}

int count_pt(std::string str)
{
	int i = 0;
	int k = 0;
	
	if (str.empty())
		return (k);
	while (str[i])
	{
		if (str[i] == '.')
			k++;
		i++;	
	}
	return (k);
}

std::string get_type(std::string str)
{
	errno = 0;
	char *endstr;	
	double value = std::strtod(str.c_str(), &endstr);	

	if (errno == ERANGE)
		throw (ScalarConverter::OutOfRange());		
	if (std::string(endstr) == str) // conversion failed at first	
		throw (ScalarConverter::Invalid());		
	if (endstr && (endstr[0] == 'f' || endstr[0] == 'F'))
	{
		if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max()
		 || ( value != 0 && std::abs(value) < std::numeric_limits<float>::min()))		
			throw (ScalarConverter::OutOfRange());
		else
			return ("float");
	}
	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		return ("double");	
	if (count_pt(str) > 0)
	{
		if (count_pt(str) == count_pt(std::string(endstr)))		
			return ("int");		
		else
			return ("double");
	}
	return ("int");
}

void ScalarConverter::convert(std::string str)
{
	char c = 0;
	int i = 0;	
	float f = 0;
	double d = 0;
	bool print_char = true;
	bool print_int = true;	
	
	if (str.empty())		
		throw (ScalarConverter::Invalid());
	if (is_nan(str))
	{		
		f = std::numeric_limits<float>::quiet_NaN();
		d = std::numeric_limits<double>::quiet_NaN();
		print_char = false;
		print_int = false;
	}
	else if (is_inf(str) == 1)
	{
		f = std::numeric_limits<float>::infinity();
		d = std::numeric_limits<double>::infinity();
		print_char = false;
		print_int = false;
	}
	else if (is_inf(str) == -1)
	{
		f = -std::numeric_limits<float>::infinity();
		d = -std::numeric_limits<double>::infinity();
		print_char = false;
		print_int = false;
	}
	else if (is_char(str))
	{
		// std::cout << "type = char" << std::endl;
		c = str.at(0);
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);		
	}
	else
	{		
		char *endstr = NULL;		
		std::string type = get_type(str);		
		// std::cout << "type = " << type << std::endl;		
		
		if (type == "int")
		{
			i = std::atoi(str.c_str());		
			c = static_cast<char>(i);		
			f = static_cast<float>(i);
			d = static_cast<double>(i);
		}
		else if (type == "float")
		{			
			f = std::strtof(str.c_str(), &endstr);
			c = static_cast<char>(f);
			i = static_cast<int>(f);			
			d = static_cast<double>(f);					
		}
		else if (type == "double")
		{			
			d = std::strtod(str.c_str(), &endstr);
			c = static_cast<char>(d);
			i = static_cast<int>(d);			
			f = static_cast<float>(d);			
		}
		else
			throw (ScalarConverter::Invalid());
	}
		
	// output
	if (print_char && is_displayable(c))
		std::cout << "char  : " << c << std::endl;
	else if (print_char && !is_displayable(c))		
		std::cout << "char  : Non displayable" << std::endl;	
	else 	
		std::cout << "char  : impossible" << std::endl;
	if (print_int)
		std::cout << "int   : " << i << std::endl;
	else
		std::cout << "int   : impossible" << std::endl; 	
	std::cout << "float : " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;	
}
