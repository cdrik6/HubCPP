/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draft.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 05:37:40 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/15 05:38:09 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

//************************************************ */
//*********** ni special ni char len >=2 ************
//************************************************ */

// first char = '+' or '-' or digit or '.'
int get_sign(std::string str, int *i)
{
	if (str[0] == '+')	
	{
		*i = 1;
		return (1);
	}		
	if (str[0] == '-')
	{
		*i = 1;
		return (-1);		
	}
	if (!isdigit(str[0]) && str[0] != '.')	
		throw(ScalarConverter::Invalid());
	return (1);		
}

std::string get_mantisse(std::string str, int *i)
{
	std::string m = ""; //mantisse
	
	while(str[*i] && (str[*i] != '.' || str[*i] != 'f' || str[*i] != 'F' 
			|| str[*i] != 'e' || str[*i] != 'E'))
	{
		if (!isdigit(str[*i]) && *i == 1)	
			throw(ScalarConverter::Invalid());			
		if (isdigit(str[*i]))
			m = m + str[*i];
		else
		{
			//is_break = true;
			break;					
		}
		i++;
	}
	return (m);	
}

std::string get_fractional(std::string str, int *i)
{
	std::string frac = ""; //fractionnal
	
	while (str[*i] && (str[*i] != 'f' || str[*i] != 'F' 
			|| str[*i] != 'e' || str[*i] != 'E'))
	{
		if (isdigit(str[*i]))
			frac = frac + str[*i];
		else
			break;
		i++;		
	}
	return (frac);
}

int get_sign_expo(std::string str, int *i)
{
	if (str[*i] == '+')	
	{
		*i++;
		return (1);
	}		
	if (str[*i] == '-')
	{
		*i++;
		return (-1);
	}
	return (1);
}

std::string get_expo(std::string str, int *i)
{
	std::string expo = ""; //exposant
	
	while (str[*i] && (str[*i] != 'f' || str[*i] != 'F'))
	{
		if (isdigit(str[*i]))
			expo = expo + str[*i];
		else
			break;
		i++;		
	}
	return (expo);
}



void number(std::string str)
{
	int i = 0; 
	int sign = 1;	
	std::string m = ""; //mantisse
	std::string frac = ""; //fractionnal
	std::string expo = ""; //exposant	
	bool is_point = false;
	bool is_expo = false;
	int sign_expo = 1;
	bool is_f = false;
	// t_number nbr = {0};

	sign = get_sign(str, &i);
	m = get_mantisse(str, &i);	
	if (str[i] && str[i] == '.')
	{
		is_point = true;
		i++;
		frac = get_fractional(str, &i);		
	}
	if (str[i] && (str[i] == 'e' || str[i] == 'E'))
	{
		is_expo = true;
		i++;
		sign_expo = get_sign_expo(str, &i);
		expo = get_expo(str, &i);		
	}
	if (str[i] && (str[i] == 'f' || str[i] == 'F'))
		is_f = true;

			
				
	// if (number > std::numeric_limits<int>::max() || number < std::numeric_limits<int>::min())	
}
