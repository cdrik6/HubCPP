/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:21:35 by caguillo          #+#    #+#             */
/*   Updated: 2024/10/31 20:08:45 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	// Parsing
	if (argc != 2)
		return(std::cout << "Usage: ./harlFilter [DEBUG|INFO|WARNING|ERROR]" << std::endl, KO);
	// Declaration
	Harl toto;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int level_nbr = 0;
	for (int i = 0; i < 4; i++)
	{
		if (levels[i].compare(argv[1]) == 0)
		{
			level_nbr = i + 1;
			break ;
		}
	}
	// Cases
	switch (level_nbr)
	{
		default: std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;	
			break;
		case 1:
			std::cout << "[ DEBUG ]" << std::endl;
			toto.complain("DEBUG");
			std::cout << std::endl;
		case 2:
			std::cout << "[ INFO ]" << std::endl;
			toto.complain("INFO");
			std::cout << std::endl;			
		case 3:
			std::cout << "[ WARNING ]" << std::endl;
			toto.complain("WARNING");
			std::cout << std::endl;
		case 4:
			std::cout << "[ ERROR ]" << std::endl;
			toto.complain("ERROR");
			std::cout << std::endl;
	}
	return (OK);
}
