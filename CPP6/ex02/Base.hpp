/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 03:41:44 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/17 05:08:16 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib>
# include <exception>

class Base
{
    public:    
        virtual ~Base();
};

class A : public Base
{

};

class B : public Base
{

};

class C : public Base
{

};

Base *generate(void);
void identify(Base* p);
void identify(Base& p);


#endif
