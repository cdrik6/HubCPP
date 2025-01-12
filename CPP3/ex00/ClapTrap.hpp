/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 02:56:16 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/11 03:22:41 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>
# include <cstdlib>

class ClapTrap
{
  private:
	  std::string _name;
	  unsigned int _hit;
    unsigned int _energy;
    unsigned int _damage;

  public:
    //
	  ClapTrap();
	  ClapTrap(std::string name);
	  ClapTrap(const ClapTrap& other);
	  ClapTrap& operator=(const ClapTrap& other);
	  ~ClapTrap();
    //
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);    
    //
    std::string get_name(void) const;
    unsigned int get_hit(void) const;
    unsigned int get_energy(void) const;
    unsigned int get_damage(void) const;
    void set_hit(unsigned int hit_points);
    void set_energy(unsigned int energy_points);
    void set_damage(unsigned int damage_points);
};

#endif
