/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 03:31:54 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/14 03:40:48 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
  protected:
	  std::string _type;

  public:
	  //
    WrongAnimal();
    WrongAnimal(std::string type);
	  WrongAnimal(const WrongAnimal& other);
	  WrongAnimal& operator=(const WrongAnimal& other);
	  ~WrongAnimal();
    // 
    std::string get_type(void) const;
    //
    void makeSound(void) const;
};

#endif
