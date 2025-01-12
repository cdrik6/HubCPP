/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 03:03:03 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/08 05:24:09 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
        ShrubberyCreationForm();
        
    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);
        virtual ~ShrubberyCreationForm();
        //
        void execute(Bureaucrat const& executor) const;
        // AForm *clone(std::string const& target) const;
        //
        class FileOpenException : public std::exception
        {
          public:
            virtual const char* what() const throw();
        };
};

#endif

// NB
// void execute(Bureaucrat const& executor) const;
// or 
// virtual void execute(Bureaucrat const& executor) const;
// No need to write virtual (done on the base class, it remains virtual in all derived classes)
// Do you need virtual? No, but it’s allowed.