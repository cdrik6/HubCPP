/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:26:46 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/17 06:44:11 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data tata = {0};
	Data *dataptr = NULL;
	uintptr_t raw;
	
	tata.c = 'c';
	tata.i = 1;		
	
	std::cout << "---------------- Data at start ------" << std::endl;
	std::cout << "Address of Data : " << &tata << std::endl;
	std::cout << "char  : " << tata.c << std::endl;
	std::cout << "int   : " << tata.i << std::endl;	
	std::cout << std::endl;
	
	std::cout << "---------------- Serialization ------" << std::endl;
	raw = Serializer::serialize(&tata);	
	std::cout << "Data serialized into Raw : " << raw << std::endl;	
	std::cout << std::endl;
	
	std::cout << "------ Deserialization of Raw -> get back Data ------" << std::endl;
	dataptr = Serializer::deserialize(raw);	
	std::cout << "Get back the address of Data : " << dataptr << std::endl;
	std::cout << "char  : " << (*dataptr).c << std::endl;
	std::cout << "int   : " << (*dataptr).i << std::endl;	
	std::cout << std::endl;
	
	return (0);
}


// check alignment
// #include <cstddef>
// std::cout << "Size of Data: " << sizeof(Data) << std::endl;
// std::cout << "Offset of c: " << offsetof(Data, c) << std::endl;
// std::cout << "Offset of i: " << offsetof(Data, i) << std::endl;
// std::cout << "Offset of f: " << offsetof(Data, f) << std::endl;
// std::cout << "Offset of d: " << offsetof(Data, d) << std::endl;

// #include <stdio.h>
// printf("ici %f\n", tata.d);
// std::cout << "float : " << (*dataptr).f << "f"<< std::endl;
// std::cout << "double: " << (*dataptr).d << std::endl;	