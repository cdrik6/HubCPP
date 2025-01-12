/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:39:47 by caguillo          #+#    #+#             */
/*   Updated: 2024/10/29 01:28:01 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

#ifndef HUMANB_HPP
# define HUMANB_HPP

class HumanB
{
  private:
	std::string _nameB;
	Weapon *_weaponB; //no need to initialized (better to NULL)

  public:
	HumanB(std::string nameB);
	~HumanB();
	void attack(void);
	// void setWeapon(Weapon weapon); // case 1 --> address of a copy  
	void setWeapon(Weapon& weapon); // case 2 --> address of the original
  // void setWeapon(Weapon& weapon); // case 3 --> value somewhere, where ?  
  
  // // tool to check:
	// Weapon *getWeapon(void);
};

#endif
