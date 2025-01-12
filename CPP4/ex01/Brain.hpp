/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 04:41:47 by caguillo          #+#    #+#             */
/*   Updated: 2024/11/15 05:15:42 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>
# include <cstdlib>

# define ID_NBR 100

class Brain
{
  private:
    std::string _ideas[ID_NBR];
    
  public:
    Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    ~Brain();
    std::string get_ideas(int i) const;
    void set_ideas(int i, std::string goodIdea);
};



#endif