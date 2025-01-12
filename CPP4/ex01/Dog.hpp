/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 03:31:54 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/15 05:22:39 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
  private:
    Brain *_dogBrain;
    
  public:
    //
    Dog();    
	  Dog(const Dog& other);
	  Dog& operator=(const Dog& other);
	  virtual ~Dog();
    //
	  virtual void makeSound(void) const;
    Brain& get_dogBrain(void) const;    
};

#endif