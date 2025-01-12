/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 03:31:54 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/15 05:38:23 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
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