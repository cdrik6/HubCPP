/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 03:31:54 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/14 03:38:46 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
  protected:
	  std::string _type;

  public:
	  //
    Animal();
    Animal(std::string type);
	  Animal(const Animal& other);
	  Animal& operator=(const Animal& other);
	  virtual ~Animal();
    // 
    std::string get_type(void) const;
    //
    virtual void makeSound(void) const;
};

#endif
