/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 04:09:23 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/20 04:40:47 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

// void norefSound(Animal const animal)
// {
// 	animal.makeSound();
// }

// void refSound(Animal const& animal)
// {
// 	animal.makeSound();
// }

int	main(void)
{
	std::cout << "------------------------  Virtual + Pointeur  --------------------------------------" << std::endl;
	// virtual + pointeur
	const Animal	*meta = new Animal();
	std::cout << std::endl;
	const Animal	*i = new Cat();
	std::cout << std::endl;
	const Animal	*j = new Dog();
	std::cout << std::endl;
	
	std::cout << "Animal is type of a: " << (*meta).get_type() << std::endl;	
	std::cout << "Sound of an Animal: "; (*meta).makeSound();
	std::cout << std::endl;
	
	std::cout << "Cat is type of a: " << (*i).get_type() << std::endl;
	std::cout << "Sound of a Cat: "; (*i).makeSound();	
	std::cout << std::endl;
	
	std::cout << "Dog is type of a: " << (*j).get_type() << std::endl;	
	std::cout << "Sound of a Dog: "; (*j).makeSound();	
	std::cout << std::endl;

	delete meta;
	std::cout << std::endl;
	delete i;
	std::cout << std::endl;
	delete j;
	std::cout << std::endl;
	

	std::cout << "------------------------  noVirtual + Pointeur  ------------------------------------" << std::endl;
	// No virtual
	const WrongAnimal	*wrongmeta = new WrongAnimal();
	std::cout << std::endl;
	const WrongAnimal	*wrongi = new WrongCat();
	std::cout << std::endl;	
	
	std::cout << "WrongAnimal is type of a: " << (*wrongmeta).get_type() << std::endl;	
	std::cout << "Sound of a WrongAnimal: "; (*wrongmeta).makeSound();
	std::cout << std::endl;
	
	std::cout << "WrongCat is type of a: " << (*wrongi).get_type() << std::endl;
	std::cout << "Sound of a WrongCat: "; (*wrongi).makeSound();	// bad sound here
	std::cout << std::endl;
	
	delete wrongmeta;
	std::cout << std::endl;
	delete wrongi; // bad destructor here
	std::cout << std::endl; 
	
	
	// std::cout << "------------------------  Virtual + Ref/noRef  --------------------------------------" << std::endl;
	// // virtual + reference needed in extern function, otherwise weird
	// const Animal	toto;	
	// const Cat	kit;	
	// const Dog	rex;
	// std::cout << std::endl;
		
	// std::cout << "Animal is type of a: " << toto.get_type() << std::endl;	
	// std::cout << "Sound of an Animal: "; toto.makeSound();
	// std::cout << "Sound of an Animal with ref: "; refSound(toto);
	// std::cout << "Sound of an Animal no ref: " << std::endl;
	// norefSound(toto);
	// std::cout << std::endl;
	
	// std::cout << "Cat is type of a: " << kit.get_type() << std::endl;
	// std::cout << "Sound of a Cat: "; kit.makeSound();
	// std::cout << "Sound of a Cat with ref: "; refSound(kit);
	// std::cout << "Sound of a Cat no ref: " << std::endl;
	// norefSound(kit); // copy of a Cat inside an animal, so sound of an animal, not a Cat, destruct of the Cat copy
	// std::cout << std::endl;
	
	// std::cout << "Dog is type of a: " << rex.get_type() << std::endl;	
	// std::cout << "Sound of a Dog: ";rex.makeSound();
	// std::cout << "Sound of a Dog with ref: "; refSound(rex);
	// std::cout << "Sound of a Dog no ref: " << std::endl;
	// norefSound(rex); // copy of a Dog inside an animal, so sound of an animal, not a Dog, destruct of the Dog copy
	// std::cout << std::endl;
	
    
	return (0);
}
