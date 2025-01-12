/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 05:32:57 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/07 22:55:08 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>
# define HIGH 1
# define LOW 150
# include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;        
        Bureaucrat();
        
    public:                
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();
        //
        const std::string getName() const;        
        int getGrade() const;
        void increment();
        void decrement();
        void signForm(Form& doc) const;
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
};

std::ostream& operator<<(std::ostream& output, const Bureaucrat& bartleby);

#endif