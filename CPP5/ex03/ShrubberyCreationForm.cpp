/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 03:27:15 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/08 05:33:09 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("shrubbery creation", 145, 137),
_target(target)
{
        
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : 
AForm(other.getName(), other.getGradeSign(), other.getGradeExec()), _target(other._target)
{
    
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this == &other)
        return(*this);
    _target = other._target;
    return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    if (getIsSigned() == false)       
        throw (ShrubberyCreationForm::NotSignedException());
    if (executor.getGrade() > getGradeExec())        
        throw (ShrubberyCreationForm::GradeTooLowException());                    
    std::ofstream outfile((_target + "_shrubbery").c_str());
    if (!outfile)
        throw(ShrubberyCreationForm::FileOpenException());    
    outfile << "         x"          << std::endl;
    outfile << "         x"          << std::endl;
    outfile << "        xxx"         << std::endl;
    outfile << "       xxxxx"        << std::endl;
    outfile << "      xxxxxxx"       << std::endl;
    outfile << "     xxxxxxxxx"      << std::endl;
    outfile << "    xxxxxxxxxxx"     << std::endl;
    outfile << "    xxxxxxxxxxx"     << std::endl;
    outfile << "    xxxxxxxxxxx"     << std::endl;
    outfile << "    xxxxxxxxxxx"     << std::endl;
    outfile << "     xxxxxxxxx"      << std::endl;
    outfile << "      xxxxxxx"       << std::endl;
    outfile << "        xxx"         << std::endl;
    outfile << "        xxx"         << std::endl;
    outfile << "        xxx"         << std::endl;        
}

const char* ShrubberyCreationForm::FileOpenException::what() const throw()
{
    return ("Error: opening failed");
}

// AForm *ShrubberyCreationForm::clone(std::string const& target) const
// {
//     return (new ShrubberyCreationForm(target));
// }