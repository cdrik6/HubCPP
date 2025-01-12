/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 03:31:54 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/14 02:42:44 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
  public:
    // 
    Cat();    
	  Cat(const Cat& other);
	  Cat& operator=(const Cat& other);
	  virtual ~Cat();
    // 
	  virtual void makeSound(void) const;
};

#endif