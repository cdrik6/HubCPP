/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 23:20:00 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/06 01:28:42 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{    
	std::cout << "Bureaucrat Bartleby: ";
	try
    {
        Bureaucrat B("Bartleby", 11);
        std::cout << "OK"<< std::endl;
        std::cout << B << std::endl; // operator Bureaucrat        
        std::cout << std::endl;
        
        std::cout << "Form00: ";
        try
        {
            Form f00("Form00", 0, 2);            
            std::cout << "OK"<< std::endl;
        }
        catch(std::exception& e)
        {           
            std::cout <<  e.what() << std::endl;
        }
        std::cout << std::endl;
                
        Form f12("Form12", 12, 2);
        Form f10("Form10", 10, 2);
        std::cout << f12 << std::endl;        
        std::cout << f10 << std::endl;        
        B.signForm(f12);
        B.signForm(f10);
        std::cout << std::endl;
        
        std::cout << f12 << std::endl;
        std::cout << f10 << std::endl;
    }
	catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }    
                
	return (0);
}

// try { f10.beSigned(B); }
// catch(std::exception& e){        
//     std::cout << e.what() << std::endl;
// }    