/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:20:25 by caguillo          #+#    #+#             */
/*   Updated: 2024/10/21 22:54:53 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string get_ten(std::string str);

// Constructor // initialisation // all 0 by default?
PhoneBook::PhoneBook(void)
{
	// index = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void PhoneBook::add(int *idx)
{
	Contact	contact;
	int		j;

	contact.get_contact();
	if (*idx == 8)
	{
		j = 0;
		while (j < 7)
		{
			contacts[j] = contacts[j + 1];
			j++;
		}
		*idx = *idx - 1;
	}
	contacts[*idx] = contact;
	// std::cout << "add" << std::endl;
	// std::cout << contacts[*idx].get_first() << std::endl;
}

void PhoneBook::search(int index)
{
	int	i = 0;
	std::string nbr = "";
    
	// Display
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	while (i < index)
	{
		std::cout << "|         " << i + 1;
		std::cout << "|";
		std::cout << get_ten(contacts[i].get_first());
		std::cout << "|";
		std::cout << get_ten(contacts[i].get_last());
		std::cout << "|";
		std::cout << get_ten(contacts[i].get_nick());
		std::cout << "|" << std::endl;
		i++;
	}
    
	// Search
	if (index > 0)
	{
		std::cout << "INDEX? ";
		std::getline(std::cin, nbr);
		if (nbr.size() == 1 && nbr[0] >= '1' && nbr[0] - '0' <= index)
		{
			std::cout << "First Name    : " << contacts[nbr[0] - '0' - 1].get_first() << std::endl;
			std::cout << "Last Name     : " << contacts[nbr[0] - '0' - 1].get_last() << std::endl;
			std::cout << "Nickname      : " << contacts[nbr[0] - '0' - 1].get_nick() << std::endl;
			std::cout << "Phone Number  : " << contacts[nbr[0] - '0' - 1].get_phone() << std::endl;
			std::cout << "Darkest Secret: " << contacts[nbr[0] - '0' - 1].get_secret() << std::endl;
		}
		else
			std::cout << "Wrong index." << std::endl;
	}
}

std::string get_ten(std::string str)
{
	std::string ten = "";
	unsigned int i = 0;

	if (str.size() == 10)
		return (str);
	if (str.size() > 10)
	{
		ten = str.substr(0, 9) + ".";
		return (ten);
	}
	while (i < 10 - str.size())
	{
		ten = ten + " ";
		i++;
	}
	return (ten + str);
}