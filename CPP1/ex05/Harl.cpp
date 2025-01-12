/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:20:25 by caguillo          #+#    #+#             */
/*   Updated: 2024/10/31 02:31:55 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// Default Constructor
Harl::Harl(void)
{
}

// Destructor
Harl::~Harl(void)
{
}

void Harl::complain(std::string level)
{		
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			((*this).*functions[i])();			
			break ;
		}
	}
}

// Private functions
void Harl::debug(void)
{
	std::cout << "this is a DEBUG message" << std::endl;
}

void Harl::info(void)
{
	std::cout << "this is an INFO message" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "this is a WARNING message" << std::endl;
}

void Harl::error(void)
{
	std::cout << "this is an ERROR message" << std::endl;
}

// NB without this --> il faut une instance
// void Harl::complain(std::string level)
// {
// 	Harl toto;
	
// 	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
// 	void (Harl::*functions[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
// 	for (int i = 0; i < 4; i++)
// 	{
// 		if (levels[i] == level)
// 		{
// 			//((*this).*functions[i])();
// 			(toto.*functions[i])();
// 			break ;
// 		}
// 	}
// }