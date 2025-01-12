/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 03:19:01 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/08 05:23:55 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"


class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
        PresidentialPardonForm();
        
    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm&);
        virtual ~PresidentialPardonForm();
        //
        void execute(Bureaucrat const& executor) const;
        // AForm *clone(std::string const& target) const;
};

#endif