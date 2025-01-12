/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 04:08:49 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/08 05:24:33 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("robotomy request", 72, 45),
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
        throw (RobotomyRequestForm::NotSignedException());
    if (executor.getGrade() > getGradeExec())
        throw (RobotomyRequestForm::GradeTooLowException());
    std::cout << "Drrr drrr" << std::endl;    
    if (rand() % 2 == 0)        
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "The robotomy of " << _target << " failed" << std::endl;
}

// AForm *RobotomyRequestForm::clone(std::string const& target) const
// {
//     return (new RobotomyRequestForm(target));
// }
