/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:21:35 by caguillo          #+#    #+#             */
/*   Updated: 2024/10/28 23:48:23 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;
	
	std::cout << "The memory address of the string variable: " << &brain << std::endl;
	std::cout << "The memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "The value of the string variable: " << brain << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;
	std::cout << std::endl;
	
	// std::string string = brain;
	// brain = "toto";
	// std::cout << "The value of the string variable: " << brain << std::endl;
	// std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
	// std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;
	// std::cout << "The value pointed to by string: " << string << std::endl;
	
	// stringREF = "change";
    // std::cout << "Memory address of the string variable: " << &brain << std::endl;
    // std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    // std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;
	// std::cout << std::endl;
    // std::cout << "Value of the string variable: " << brain << std::endl;
    // std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    // std::cout << "Value of stringREF: " << stringREF << std::endl;
	
	return (0);
}
