/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 04:08:49 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/08 05:01:08 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45),
_target(target)
{
    srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : 
AForm(other.getName(), other.getGradeSign(), other.getGradeExec()), _target(other._target)
{
    
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this == &other)
        return(*this);
    _target = other._target;
    return(*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    if (getIsSigned() == false)       
        throw (AForm::NotSignedException());
    if (executor.getGrade() > getGradeExec())
        throw (AForm::GradeTooLowException());
    std::cout << "Drrr drrr dr dre" << std::endl;    
    if (rand() % 2 == 0)        
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "The robotomy of " << _target << " failed" << std::endl;
}
