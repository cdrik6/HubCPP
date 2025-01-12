/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 03:43:36 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/17 05:31:55 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base()
{    
}

Base *generate(void)
{
    int k = rand() % 3;
    
    if (k == 0)
        return (new A());
    else if (k == 1)
        return (new B());
    else 
        return (new C());    
}

void identify(Base* p)
{    
    if (dynamic_cast<A*>(p))
        std::cout << "Type A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Type B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Type C" << std::endl;
    else     
        std::cout << "Undefined type" << std::endl;    
}

void identify(Base& p)
{
    A a;
    B b;
    C c;
    
    try
    {
        a = dynamic_cast<A&>(p);
        std::cout << "Type A" << std::endl;        
    }
    catch(std::exception& e)
    {                
        try
        {
            b = dynamic_cast<B&>(p);
            std::cout << "Type B" << std::endl;        
        }
        catch(std::exception& e)
        {                
            try
            {
                c = dynamic_cast<C&>(p);
                std::cout << "Type C" << std::endl;        
            }
            catch(std::exception& e)
            {                
                std::cout << "Undefined type" << std::endl;
            }
        }
    }   
}

// NB
// dynamic_cast<A&>(p) --> do not return a boolean
// use dynamic_cast with a reference, it does not return a pointer or a boolean value.
// dynamic_cast<A&>(p); --> If the cast fails (i.e. p is not of type A),
// a std::bad_cast exception is thrown.