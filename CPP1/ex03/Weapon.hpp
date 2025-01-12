/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:27:16 by caguillo          #+#    #+#             */
/*   Updated: 2024/10/29 01:56:28 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
  private:
	std::string _type;

  public:
	Weapon();
	Weapon(std::string initType);
	~Weapon();
	void setType(std::string newType);
	const std::string &getType(void);
};

#endif