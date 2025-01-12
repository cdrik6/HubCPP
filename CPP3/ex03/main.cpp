/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 03:46:28 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/11 18:21:57 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
    // init
    srand(time(NULL));
    DiamondTrap toto("TOTO");    
    DiamondTrap titi("TITI");
    std::cout << toto.get_name() << " : hit : " << toto.get_hit() << std::endl;
    std::cout << toto.get_name() << " : energy : " << toto.get_energy() << std::endl;
    std::cout << toto.get_name() << " : damage : " << toto.get_damage() << std::endl;
    std::cout << titi.get_name() << " : hit : " << titi.get_hit() << std::endl;
    std::cout << titi.get_name() << " : energy : " << titi.get_energy() << std::endl;
    std::cout << titi.get_name() << " : damage : " << titi.get_damage() << std::endl;
    std::cout << std::endl;
    // Who am I
    toto.whoAmI();
    titi.whoAmI();    
    std::cout << std::endl;
    // Gate keeper  + high fives
    toto.highFivesGuys();    
    toto.guardGate();
    titi.highFivesGuys();
    titi.guardGate();
    std::cout << std::endl;    
    // fights
    unsigned int tmp_energy;
    for (int i = 0; i < 10; i++)
    {
        std::cout << "------------------------- Fight " << i + 1 << " ---------------------------" <<std::endl;
        std::cout << std::endl;        
        // fight
        tmp_energy = toto.get_energy();       
        toto.attack(titi.get_name());        
        if (toto.get_hit() && tmp_energy)
        {
            titi.takeDamage(toto.get_damage());    
            titi.beRepaired(rand()%10);
        }
        std::cout << std::endl;
        // fight back
        tmp_energy = titi.get_energy();
        titi.attack(toto.get_name());
        if (titi.get_hit() && tmp_energy)
        {
            toto.takeDamage(titi.get_damage());    
            toto.beRepaired(rand()%10);    
        }
        std::cout << std::endl;
    }
    // result
    std::cout << "------------------------- Result ----------------------------" <<std::endl;
    std::cout << toto.get_name() << ": health level: " << toto.get_hit() << std::endl;
    std::cout << titi.get_name() << ": health level: " << titi.get_hit() << std::endl;        
    std::cout << "Winner: "<< (toto.get_hit() > titi.get_hit() ? toto.get_name() : titi.get_name()) << std::endl;
    std::cout << std::endl;
    return (0);
}
