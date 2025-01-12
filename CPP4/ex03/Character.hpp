/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 03:47:55 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/20 02:17:25 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# define SLOTS 4

class Character : public ICharacter
{
   private:
    std::string _name;
    AMateria *_inventory[SLOTS];
    AMateria **_left;    
    int _sizeLeft;
    
   public:
    Character();
    Character(std::string const& name);
    Character(const Character& other);
    Character& operator=(const Character& other);
    virtual ~Character();
    //
	virtual std::string const &getName() const;
	virtual void equip(AMateria *m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter &target);
    //
    virtual void updateLeft(AMateria* m);    
};

#endif