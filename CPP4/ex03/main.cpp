/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 00:52:27 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/20 03:52:51 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"


int	main(void)
{
	std::cout << "-- 1 ---------------- perfect case -------------------------------" << std::endl;
    IMateriaSource *src = new MateriaSource();    
    std::cout << std::endl;
           
    (*src).learnMateria(new Ice());
	(*src).learnMateria(new Cure());      
    std::cout << std::endl;
    
	ICharacter *me = new Character("me");
    std::cout << std::endl;
	
    AMateria *tmp = NULL;
	tmp = (*src).createMateria("ice");
    std::cout << std::endl;
	(*me).equip(tmp);
    std::cout << std::endl;
	tmp = (*src).createMateria("cure");
    std::cout << std::endl;
	(*me).equip(tmp);    
    std::cout << std::endl;
    // if tmp not equipped, tmp to be deleted (by hand) --> case 4
    // if inside slots, deleted with destructor of character me (nothing to do)
    // if full slots, deleted (nothing to do)
     
	ICharacter *bob = new Character("bob");
    std::cout << std::endl;
    
    std::cout << "------------------- output requested by subject ------------------" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
    
	delete bob;
    std::cout << std::endl;
	delete me;
    std::cout << std::endl;
	delete src;
    std::cout << std::endl;    
    
    //
    std::cout << "-- 2 ---------------- Full MateriaSource ----------------------------" << std::endl;

    IMateriaSource *src2 = new MateriaSource();    
    std::cout << std::endl;    
    (*src2).learnMateria(new Ice());
	(*src2).learnMateria(new Cure());    
    (*src2).learnMateria(new Ice());
    (*src2).learnMateria(new Cure());
    (*src2).learnMateria(new Cure());
    std::cout << std::endl;
    delete src2;
    std::cout << std::endl;


    //
    std::cout << "-- 3 ---------------- Full equip ----------------------------" << std::endl;
    IMateriaSource *src3 = new MateriaSource();    
    std::cout << std::endl;    
    (*src3).learnMateria(new Ice());
	(*src3).learnMateria(new Cure());

    ICharacter *me3 = new Character("me3");
    std::cout << std::endl;
    
    AMateria *tmp3;
    tmp3 = (*src3).createMateria("cure");
    std::cout << std::endl;
    (*me3).equip(tmp3);
    std::cout << std::endl;
    tmp3 = (*src3).createMateria("cure");
    std::cout << std::endl;
    (*me3).equip(tmp3);
    std::cout << std::endl;
    tmp3 = (*src3).createMateria("ice");
    std::cout << std::endl;
    (*me3).equip(tmp3);
    std::cout << std::endl;
    tmp3 = (*src3).createMateria("cure");
    std::cout << std::endl;
    (*me3).equip(tmp3);
    std::cout << std::endl;
    tmp3 = (*src3).createMateria("ice");
    std::cout << std::endl;
    (*me3).equip(tmp3);
    std::cout << std::endl;
    
    delete me3;
    std::cout << std::endl;	
    delete src3;
    std::cout << std::endl;

    //
    std::cout << "-- 4 ---------------- No equip ----------------------------" << std::endl;
    IMateriaSource *src4 = new MateriaSource();    
    std::cout << std::endl;    
    (*src4).learnMateria(new Ice());
	(*src4).learnMateria(new Cure());

    ICharacter *me4 = new Character("me4");
    std::cout << std::endl;
    
    AMateria *tmp4;
    tmp4 = (*src4).createMateria("cure");
    
    delete tmp4;
    std::cout << std::endl;	
    delete me4;
    std::cout << std::endl;	
    delete src4;
    std::cout << std::endl;


    //
    std::cout << "-- 5 ---------------- no materia + unequip ----------------------------" << std::endl;
    IMateriaSource *src5 = new MateriaSource();
    std::cout << std::endl;
           
    (*src5).learnMateria(new Ice());
	(*src5).learnMateria(new Cure());      
    std::cout << std::endl;
    
	ICharacter *me5 = new Character("me5");
    std::cout << std::endl;
	
    AMateria *tmp5 = NULL;
    tmp5 = (*src5).createMateria("no materia");
    (*me5).equip(tmp5);
    std::cout << std::endl;
	tmp5 = (*src5).createMateria("ice");    
    std::cout << std::endl;
	(*me5).equip(tmp5);
    std::cout << std::endl;
	tmp5 = (*src5).createMateria("cure");
    std::cout << std::endl;
	(*me5).equip(tmp5);
    std::cout << std::endl;
    
	ICharacter *bob5 = new Character("bob5");
    std::cout << std::endl;    
	(*me5).use(0, *bob5);
	(*me5).use(1, *bob5);    
    std::cout << std::endl;
     
    (*me5).unequip(2);    
    (*me5).unequip(0);
    (*me5).unequip(1);
    (*me5).unequip(5);    
    (*me5).use(0, *bob5);
	(*me5).use(1, *bob5);
    std::cout << std::endl;
    
	delete bob5;
    std::cout << std::endl;
	delete me5;
    std::cout << std::endl;
	delete src5;
    std::cout << std::endl;
    
    return 0;
}

/* draft */
// AMateria *icy = new Ice();
// AMateria *cury = new Cure();
// src->learnMateria(icy);
// src->learnMateria(cury);  