/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 03:31:54 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/15 05:43:06 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal // Abstract Animal Class
{
  protected:
	  std::string _type;    

  public:
	  //
    AAnimal();
    AAnimal(std::string type);
	  AAnimal(const AAnimal& other);
	  AAnimal& operator=(const AAnimal& other);
	  virtual ~AAnimal();
    // 
    std::string get_type(void) const;
    //
    virtual void makeSound(void) const = 0; // Pure virtual
};

#endif
