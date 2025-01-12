/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 03:47:43 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/08 03:30:50 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string name, int grade_sign, int grade_exec) : _name(name), _is_signed(false), _grade_exec(grade_exec), _grade_sign(grade_sign)
{
    if (grade_exec < HIGH || grade_sign < HIGH)
        throw (AForm::GradeTooHighException());
    if (grade_exec > LOW || grade_sign > LOW)
        throw (AForm::GradeTooLowException());    
}

AForm::AForm(const AForm& other) : _name(other._name), _grade_exec(other._grade_exec), _grade_sign(other._grade_sign) 
{
    if (this == &other)
    {
        std::cerr << "Error: Self-copying during construction is undefined." << std::endl;
        return;
    }    
    *this = other;
}

AForm& AForm::operator=(const AForm& other)
{
    if (this == &other)
        return (*this);
    _is_signed = other._is_signed;    
    return (*this);    
}

AForm::~AForm()
{
    
}

std::string AForm::getName() const
{
    return (_name);
}

int AForm::getGradeSign() const
{
    return (_grade_sign);
}

int AForm::getGradeExec() const
{
    return (_grade_exec);
}

bool AForm::getIsSigned() const
{
    return (_is_signed);
}

std::ostream& operator<<(std::ostream& output, const AForm& doc)
{
    output << 
    "Form name        : " << doc.getName() << std::endl; 
    if (doc.getIsSigned())
        output << "Is signed?       : true" << std::endl;
    else     
        output << "Is signed?       : false" << std::endl;
    output << "Grade to sign    : " << doc.getGradeSign() << std::endl;
    output << "Grade to execute : " << doc.getGradeExec() << std::endl;
    return (output);
    
}

void AForm::beSigned(const Bureaucrat& bartleby)
{
    if (bartleby.getGrade() > _grade_sign)
        throw (AForm::GradeTooLowException());
    _is_signed = true;
}

/******************* Exception classes ************/

const char* AForm::GradeTooHighException::what() const throw()
{ 
    return ("Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw() 
{       
    return ("Grade too low");
}

const char* AForm::NotSignedException::what() const throw()
{
    return ("The form is not signed");
}
