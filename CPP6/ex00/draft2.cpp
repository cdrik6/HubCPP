/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draft2.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 04:19:50 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/16 04:30:50 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

std::string get_type(std::string str)
{
	errno = 0;
	char *endstr;	
	double value = std::strtod(str.c_str(), &endstr);	

	if (errno == ERANGE)
	{
		std::cout << "ici errno" << std::endl;
		throw (ScalarConverter::OutOfRange());
	}	
	if (std::string(endstr) == str) // conversion failed at first
	{
		std::cout << endstr << std::endl;		
		throw (ScalarConverter::Invalid());
	}	
	if (endstr && (endstr[0] == 'f' || endstr[0] == 'F'))
	{
		if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max()
		 || abs(value) < std::numeric_limits<float>::min()) 
		{
			std::cout << value << std::endl;	
			std::cout << std::numeric_limits<float>::max() << std::endl;	
			std::cout << std::numeric_limits<float>::min() << std::endl;
			throw (ScalarConverter::OutOfRange());
		}
		else
			return ("float");
	}
	if (value > std::numeric_limits<int>::max() || value < -std::numeric_limits<int>::max())
		return ("double");	
	if (count_pt(str) > 0)
	{
		if (count_pt(str) == count_pt(std::string(endstr)))
		{
			std::cout << value << std::endl;	
			std::cout << std::numeric_limits<int>::max() << std::endl;	
			std::cout << std::numeric_limits<int>::min() << std::endl;
			return ("int");
		}
		else
			return ("double");
	}	
	std::cout << endstr << std::endl;
	std::cout << value << std::endl;						
	return ("int");
}

// while(str[i] && (str[i] != '.' || str[i] != 'f' || str[i] != 'F' || str[i] != 'e' || str[i] != 'E'))
	// {
	// 	if (!isdigit(str[i]) && i == 1)	
	// 		throw(ScalarConverter::NotNumber());			
	// 	if (isdigit(str[i]))
	// 		m = m + str[i];
	// 	else
	// 	{
	// 		is_break = true;
	// 		break;					
	// 	}
	// 	i++;
	// }

// if (value == HUGE_VAL || value == -HUGE_VAL)
	// 	std::cout << "huge" << std::endl;	
	// // double value1 = std::strtod("1e500", &endstr);
	// if (value > std::numeric_limits<double>::max())
	// 	std::cout << "over" << std::endl;	
	// std::cout << str << std::endl;
	// std::cout << str.c_str() << std::endl;
	// std::cout << "errno = " << errno << std::endl;
	// // if (errno == ERANGE)
	// // 	std::cout << "la errno" << std::endl;
	
// if (value > std::numeric_limits<double>::max() || value < -std::numeric_limits<double>::max()) //1.79769e+308
	// {
	// 	std::cout << value << std::endl;	
	// 	std::cout << std::numeric_limits<double>::max() << std::endl;	
	// 	std::cout << std::numeric_limits<double>::min() << std::endl;
	// 	throw(ScalarConverter::OutOfRange());
	// }		

// if (value < std::numeric_limits<double>::min()) //2.22507e-308
	// {
	// 	throw(ScalarConverter::OutOfRange());
	// }