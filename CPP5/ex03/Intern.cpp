/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:07:34 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/08 15:49:52 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
        
}

Intern::Intern(const Intern& other)
{
    *this = other;    
}

Intern& Intern::operator=(const Intern& other)
{
    if (this == &other)    
        return(*this);
    *this = other;
    return(*this);    
}

Intern::~Intern()
{
    
}

AForm *Intern::makeForm(std::string nameForm, std::string target)
{
    std::string nameForms[] = {"shrubbery creation","robotomy request","presidential pardon"};
    AForm* (Intern::*f_forms[])(std::string target) = {        
        &Intern::cloneShrubbery, 
        &Intern::cloneRobotomy,
        &Intern::clonePresidential
    };
    for (int i = 0; i < 3; i++)
    {
        if (nameForms[i] == nameForm)        
        {
            std::cout << "Intern creates " << nameForm << std::endl;
            return ( ((*this).*f_forms[i])(target) );
        }    
    }    
    std::cout << "Form " << nameForm << " doesn't exist, Intern can't create it" << std::endl;
    return (NULL);
}

AForm *Intern::cloneShrubbery(std::string target)
{
    return (new ShrubberyCreationForm(target));    
}

AForm *Intern::cloneRobotomy(std::string target)
{
    return (new RobotomyRequestForm(target));
}

AForm *Intern::clonePresidential(std::string target)
{
    return (new PresidentialPardonForm(target));
}


// AForm *Intern::makeForm(std::string nameForm, std::string target)
// {
//     AForm *forms[3];
//     AForm *tmp = NULL ;
    
//     forms[0] = new ShrubberyCreationForm(target); 
//     forms[1] = new RobotomyRequestForm(target); 
//     forms[2] = new PresidentialPardonForm(target);     
//     for (int i = 0; i < 3; i++)
//     {
//         if ((*forms[i]).getName() == nameForm)        
//             tmp = (*forms[i]).clone(target);        
//         delete forms[i];
//         forms[i] = NULL;            
//     }    
//     if (tmp)
//         std::cout << "Intern creates " << nameForm << std::endl;
//     else    
//         std::cout << "Form " << nameForm << " doesn't exist, Intern can't create it" << std::endl;
//     return (tmp);
// }
