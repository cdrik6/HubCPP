/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 03:03:18 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/07 22:55:33 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
  private:
    const std::string _name;
    bool _is_signed;
    const int _grade_sign;
    const int _grade_exec;
    Form();

  public:    
    Form(std::string name, int grade_sign, int grade_exec);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();
    //
    std::string getName() const;
    int getGradeSign() const;
    int getGradeExec() const;
    bool getIsSigned() const;
    void beSigned(const Bureaucrat& bartleby);    
    //
    class GradeTooHighException : public std::exception
    {
        private:
            const Form& _doc;
            std::string _error;  
        public:
            GradeTooHighException(const Form& doc);
            virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        private:
            const Form& _doc;            
            std::string _error;
        public :            
            GradeTooLowException(const Form& doc);
            virtual const char* what() const throw();                        
    };
};

std::ostream& operator<<(std::ostream& output, const Form& doc);

#endif

