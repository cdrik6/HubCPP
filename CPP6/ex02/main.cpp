/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:26:46 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/17 05:49:24 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main(void)
{
	srand(time(NULL));
	
	Base *z_ptr = generate();
	Base& z_ref = *z_ptr;	
	
	std::cout << "--- Identify type with a pointer ---" << std::endl;
	identify(z_ptr);

	std::cout << std::endl;
	std::cout << "--- Identify type with a reference ---" << std::endl;
	identify((z_ref));
	
	std::cout << std::endl;	
	delete (z_ptr);
		
	return (0);
}