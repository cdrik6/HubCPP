/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 03:03:18 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/07 22:57:54 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
  private:
    const std::string _name;
    bool _is_signed;
    const int _grade_sign;
    const int _grade_exec;
    AForm();

  public:    
    AForm(std::string name, int grade_sign, int grade_exec);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();
    //
    std::string getName() const;
    int getGradeSign() const;
    int getGradeExec() const;
    bool getIsSigned() const;
    void beSigned(const Bureaucrat& bartleby);
    //
    virtual void execute(Bureaucrat const& executor) const = 0;      
    //
    class GradeTooHighException : public std::exception
    {
        public:            
            virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {        
        public:
            virtual const char* what() const throw();                        
    };
    class NotSignedException : public std::exception
    {
        public:
            virtual const char* what() const throw();                        
    };
};

std::ostream& operator<<(std::ostream& output, const AForm& doc);

#endif

