/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 22:15:04 by caguillo          #+#    #+#             */
/*   Updated: 2024/10/19 23:27:28 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

std::string upstring(std::string str);

int	main(int argc, char **argv)
{
	int	i = 1;    	
	std::string shout = "";
    
	if (argc == 1)
		shout = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (i < argc)
		{
			if (i == 1)
				shout = upstring(argv[i]);
			else
				shout = shout + upstring(argv[i]);
			i++;
		}		
	}
    std::cout << shout << std::endl;
	return (0);
}

std::string upstring(std::string str)
{
	unsigned int i = 0;
    std::string up = "";
    
	while (i < str.size())
	{
        up.push_back(toupper(str[i]));
        i++;
	}
    return (up);
}