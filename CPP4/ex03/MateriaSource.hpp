/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 04:26:59 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/20 02:58:45 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# define SLOTS 4

class MateriaSource : public IMateriaSource
{
  private:
    AMateria *_materia[SLOTS];
    
  public:
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    MateriaSource& operator=(const MateriaSource& other);
    virtual ~MateriaSource();
    //
	  virtual void learnMateria(AMateria *);
	  virtual AMateria *createMateria(std::string const &type);  
};

#endif