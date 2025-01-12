/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 02:41:29 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/16 20:45:20 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
  public:
	  Ice();
	  Ice(const Ice& other);
	  Ice &operator=(const Ice& other);
	  virtual ~Ice();
    //
    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif