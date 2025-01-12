/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:39:51 by caguillo          #+#    #+#             */
/*   Updated: 2024/10/29 01:14:13 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
  private:
	std::string _nameA;
	Weapon& _weaponA; // ref --> must be initialized (in constructor)

  public:	
    HumanA(std::string nameA, Weapon& weaponA);
	~HumanA();
	void attack(void);
};

#endif

// no need to initiate the ref var _weaponA as the constructor does it.
