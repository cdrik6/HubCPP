/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:18:25 by caguillo          #+#    #+#             */
/*   Updated: 2024/10/23 21:57:08 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void Contact::get_contact()
{
	while (first_name == "")
	{
		std::cout << "First Name: ";
		std::getline(std::cin, first_name);
	}
	while (last_name == "")
	{
		std::cout << "Last Name: ";
		std::getline(std::cin, last_name);
	}
	while (nickname == "")
	{
		std::cout << "Nickname: ";
		std::getline(std::cin, nickname);
	}
	while (phone_number == "")
	{
		std::cout << "Phone Number: ";
		std::getline(std::cin, phone_number);
	}
	while (darkest_secret == "")
	{
		std::cout << "Darkest Secret: ";
		std::getline(std::cin, darkest_secret);
	}
}

std::string Contact::get_first()
{
	return (first_name);
}

std::string Contact::get_last()
{
	return (last_name);
}

std::string Contact::get_nick()
{
	return (nickname);
}

std::string Contact::get_phone()
{
	return (phone_number);
}

std::string Contact::get_secret()
{
	return (darkest_secret);
}
