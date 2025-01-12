/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 02:41:29 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/16 03:43:22 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
  public:
	  Cure();
	  Cure(const Cure& other);
	  Cure &operator=(const Cure& other);
	  virtual ~Cure();
    //
    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif