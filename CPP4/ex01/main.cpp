/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 04:09:23 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/20 05:21:27 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"


int	main(void)
{	
	srand(time(NULL));
	int n = 6;
	const Animal* meta[n];
		
	for (int i = 0; i < n; i++)
	{
		if (i < n / 2)		
			meta[i] = new Cat();
		else
			meta[i] = new Dog();
		(*meta[i]).makeSound();
		std::cout << std::endl;
	}
	for (int i = 0; i < n; i++)
	{
		delete meta[i];
		std::cout << std::endl;
	}	

	std::cout << "-----------------------------  Deep Cat copy test  --------------------" << std::endl;
	std::cout << std::endl;
	
	Cat kit;	
	std::cout << std::endl;
	std::cout << "kit thinks: " << kit.get_catBrain().get_ideas(n) << std::endl;
	std::cout << std::endl;
	
	Cat kat(kit);
	std::cout << std::endl;
	std::cout << "kat thinks: " << kat.get_catBrain().get_ideas(n) << std::endl;
	std::cout << std::endl;

	// be careful: Cat kot = kit; --> copy, not assignment, same as kot(kit) initialization
	Cat kot;
	kot = kit; // right assignment
	std::cout << std::endl;
	std::cout << "kot thinks: " << kot.get_catBrain().get_ideas(n) << std::endl;
	std::cout << std::endl;
	
	std::cout << "Cats changed their mind:" << std::endl;
	kit.get_catBrain().set_ideas(n, "A deep idea of Kit");
	kat.get_catBrain().set_ideas(n, "A deep idea of Kat");
	kot.get_catBrain().set_ideas(n, "A deep idea of Kot");
	std::cout << "kit thinks now: " << kit.get_catBrain().get_ideas(n) << std::endl;
	std::cout << "kat thinks now: " << kat.get_catBrain().get_ideas(n) << std::endl;
	std::cout << "kot thinks now: " << kot.get_catBrain().get_ideas(n) << std::endl;
	std::cout << std::endl;	

	// std::cout << "-----------------------------  Deep Dog copy test  --------------------" << std::endl;
	// std::cout << std::endl;
	
	// Dog kit;	
	// std::cout << std::endl;
	// std::cout << "kit thinks: " << kit.get_dogBrain().get_ideas(6) << std::endl;
	// std::cout << std::endl;
	
	// Dog kat(kit);
	// std::cout << std::endl;
	// std::cout << "kat thinks: " << kat.get_dogBrain().get_ideas(6) << std::endl;
	// std::cout << std::endl;

	// // be careful: Dog kot = kit; --> copy, not assignment, same as kot(kit) initialization
	// Dog kot;
	// kot = kit; // right assignment
	// std::cout << std::endl;
	// std::cout << "kot thinks: " << kot.get_dogBrain().get_ideas(6) << std::endl;
	// std::cout << std::endl;	
		
	return (0);
}

// NB
// shallow copy: only the addresses are copied, not the actual data they point to.
// vs deep copy

// With this shallow copy:
//     The Cat objects will share the same name memory.
//     When one Cat object is destroyed, the memory for name will be deleted.
//     If another Cat object tries to access name after deletion, you may get a segmentation fault.

// With a deep copy:
//     Each Cat object has its own separate memory for name.
//     Modifying name in one object won’t affect another.
//     When one Cat object is destroyed, it frees only its own memory, avoiding issues with dangling pointers.

// Test copy self
// Brain b(b);
// std::cout << "7th idea: " << b.get_ideas(6) << std::endl;