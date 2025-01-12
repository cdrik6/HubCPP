/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 02:56:16 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/13 03:01:17 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap // order here is important in construction
{
  private:
	  std::string _name; //shadow of ClapTrap::_name
    unsigned int _hit;
    unsigned int _energy;
    unsigned int _damage;

  public:
    //
	  DiamondTrap();
	  DiamondTrap(std::string name);
	  DiamondTrap(const DiamondTrap& other);
	  DiamondTrap& operator=(const DiamondTrap& other);
	  ~DiamondTrap();
    //
    void attack(const std::string& target);
    void whoAmI(void);
    //
    std::string get_name(void) const;
    unsigned int get_hit(void) const;
    unsigned int get_energy(void) const;
    unsigned int get_damage(void) const;
    
};

#endif
