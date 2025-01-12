/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 04:11:16 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/08 05:02:17 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5),
_target(target)
{
        
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : 
AForm(other.getName(), other.getGradeSign(), other.getGradeExec()), _target(other._target)
{
    
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this == &other)
        return(*this);
    _target = other._target;
    return(*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    if (getIsSigned() == false)       
        throw (AForm::NotSignedException());
    if (executor.getGrade() > getGradeExec())
        throw (AForm::GradeTooLowException());    
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
