/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 23:20:00 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/06 01:08:06 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	
    std::cout << "-------------- Constructor ------------" << std::endl;
    
	int i = 0;
	std::cout << "Bureaucrat A" << i << ": ";
	try
    {
       Bureaucrat A("A", i);
       std::cout << "OK"<< std::endl;
    }
	catch (std::exception &e) { std::cout << e.what() << std::endl;	}    
    
	i += 50;
	std::cout << "Bureaucrat B" << i << ": ";
	try
    {
       Bureaucrat B("B", i);
       std::cout << "OK"<< std::endl;
    }
	catch (std::exception &e) { std::cout << e.what() << std::endl;	}    
    
	i += 50;
	std::cout << "Bureaucrat C" << i << ": ";
	try
    {
       Bureaucrat C("C", i);
       std::cout << "OK"<< std::endl;
    }
	catch (std::exception &e) { std::cout << e.what() << std::endl;	}
        
	i += 50;
	std::cout << "Bureaucrat D" << i << ": ";
	try
    {
       Bureaucrat D("D", i);
       std::cout << "OK"<< std::endl;
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl;	}    
    
	i += 50;
	std::cout << "Bureaucrat E" << i << ": ";
	try
    {
       Bureaucrat E("E", i);
       std::cout << "OK"<< std::endl;
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl;	}
    std::cout << std::endl;
    
    std::cout << "-------------- Decrement ------------" << std::endl;
    Bureaucrat F("F", 150);
    try { F.decrement(); }
    catch (std::exception &e) { std::cout << e.what() << std::endl;	}
    std::cout << std::endl;

    std::cout << "-------------- Increment ------------" << std::endl;
    Bureaucrat G("G", 1);
    try { G.increment(); }
    catch (std::exception &e) { std::cout << e.what() << std::endl;	}
    std::cout << std::endl;

    std::cout << "-------------- Overload operator << ------------" << std::endl;
    std::cout << G.getName() << ", bureaucrat grade " << G.getGrade() << "." << std::endl;
    std::cout << G << std::endl;    
        
	return (0);
}
