/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 23:20:00 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/08 05:33:27 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int	main(void)
{    
	AForm* scf = NULL;
    AForm* rrf = NULL;
    AForm* ppf = NULL;
    AForm* nof = NULL;

    try
    {
        Bureaucrat A("High", 1);        
        std::cout << A << std::endl;
        Bureaucrat B("Middle", 70);        
        std::cout << B << std::endl;
        Bureaucrat C("Low", 150);        
        std::cout << C << std::endl;
        std::cout << std::endl;

        Intern someRandomIntern;
        scf = someRandomIntern.makeForm("shrubbery creation", "Santa");
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        ppf = someRandomIntern.makeForm("presidential pardon", "Minister");
        nof = someRandomIntern.makeForm("nothing", "Nobody");
        std::cout << std::endl;
        
        if (scf)
            std::cout << *scf << std::endl;
        if (rrf)
            std::cout << *rrf << std::endl;
        if (ppf)
            std::cout << *ppf << std::endl;
        if (nof)
            std::cout << *nof << std::endl;
        
        std::cout << "--- Signing ---" << std::endl;
        std::cout << std::endl;
        A.signForm(*scf);
        A.signForm(*rrf);
        A.signForm(*ppf);
        std::cout << std::endl;        
        B.signForm(*scf);
        B.signForm(*rrf);
        B.signForm(*ppf);
        std::cout << std::endl;
        C.signForm(*scf);
        C.signForm(*rrf);
        C.signForm(*ppf);
        std::cout << std::endl;
        
        std::cout << "--- Execution ---" << std::endl;
        std::cout << std::endl;
        A.executeForm(*scf);
        A.executeForm(*rrf);        
        A.executeForm(*ppf);
        std::cout << std::endl;        
        B.executeForm(*scf);
        B.executeForm(*rrf);
        B.executeForm(*ppf);
        std::cout << std::endl;
        C.executeForm(*scf);
        C.executeForm(*rrf);
        C.executeForm(*ppf);
        std::cout << std::endl;     
        
    }
	catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;        
    }    

    delete scf;
    delete rrf;
    delete ppf;
    delete nof;    
                
	return (0);
}

