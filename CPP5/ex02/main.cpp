/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 23:20:00 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/08 04:55:40 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int	main(void)
{    
	try
    {
        Bureaucrat A("High", 1);        
        std::cout << A << std::endl;
        Bureaucrat B("Middle", 70);        
        std::cout << B << std::endl;
        Bureaucrat C("Low", 150);        
        std::cout << C << std::endl;
        std::cout << std::endl;
        
        std::cout << "ShrubberyCreationForm: ";
        ShrubberyCreationForm SCF("Santa");
        std::cout << "OK" << std::endl;        
        std::cout << "RobotomyRequestForm: ";
        RobotomyRequestForm RRF("DIY");
        std::cout << "OK" << std::endl;        
        std::cout << "PresidentialPardonForm: ";
        PresidentialPardonForm PPF("Minister");
        std::cout << "OK" << std::endl;
        std::cout << std::endl;
        
        std::cout << SCF << std::endl;
        std::cout << RRF << std::endl;
        std::cout << PPF << std::endl;        
        
        std::cout << "--- Signing ---" << std::endl;
        std::cout << std::endl;
        A.signForm(SCF);
        A.signForm(RRF);
        A.signForm(PPF);
        std::cout << std::endl;        
        B.signForm(SCF);
        B.signForm(RRF);
        B.signForm(PPF);
        std::cout << std::endl;
        C.signForm(SCF);
        C.signForm(RRF);
        C.signForm(PPF);
        std::cout << std::endl;
        
        std::cout << "--- Execution ---" << std::endl;
        std::cout << std::endl;
        A.executeForm(SCF);
        A.executeForm(RRF);
        A.executeForm(PPF);
        std::cout << std::endl;        
        B.executeForm(SCF);
        B.executeForm(RRF);
        B.executeForm(PPF);
        std::cout << std::endl;
        C.executeForm(SCF);
        C.executeForm(RRF);
        C.executeForm(PPF);
        std::cout << std::endl;
        
    }
	catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }    
                
	return (0);
}

