/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:21:35 by caguillo          #+#    #+#             */
/*   Updated: 2024/10/21 21:53:53 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>


int	prompted(int index, PhoneBook *phonebook);

int	main(void)
{
	PhoneBook phonebook;
	int index = 0;	
	return (prompted(index, &phonebook));
}

int	prompted(int index, PhoneBook *phonebook)
{
	std::string todo = "";	
	
	std::cout << "ADD, SEARCH or EXIT? ";
	while (todo != "ADD" && todo != "SEARCH" && todo != "EXIT")
		std::getline(std::cin, todo);
	if (todo == "ADD")
	{
		(*phonebook).add(&index);
		index++;
		prompted(index, phonebook);
	}
	else if (todo == "SEARCH")
	{
		// std::cout << "index = " << index << std::endl;
		(*phonebook).search(index);
		prompted(index, phonebook);
	}
	return (0);
}
