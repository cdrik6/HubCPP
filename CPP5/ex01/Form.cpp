/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 03:47:43 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/08 04:40:17 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int grade_sign, int grade_exec) : _name(name), _is_signed(false), _grade_exec(grade_exec), _grade_sign(grade_sign)
{
    if (grade_exec < HIGH || grade_sign < HIGH)
        throw (Form::GradeTooHighException(*this));
    if (grade_exec > LOW || grade_sign > LOW)
        throw (Form::GradeTooLowException(*this));    
}

Form::Form(const Form& other) : _name(other._name), _grade_exec(other._grade_exec), _grade_sign(other._grade_sign) 
{
    if (this == &other)
    {
        std::cerr << "Error: Self-copying during construction is undefined." << std::endl;
        return;
    }    
    *this = other;
}

Form& Form::operator=(const Form& other)
{
    if (this == &other)
        return (*this);
    _is_signed = other._is_signed;    
    return (*this);    
}

Form::~Form()
{
    
}

std::string Form::getName() const
{
    return (_name);
}

int Form::getGradeSign() const
{
    return (_grade_sign);
}

int Form::getGradeExec() const
{
    return (_grade_exec);
}

bool Form::getIsSigned() const
{
    return (_is_signed);
}

std::ostream& operator<<(std::ostream& output, const Form& doc)
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

void Form::beSigned(const Bureaucrat& bartleby)
{
    if (bartleby.getGrade() > _grade_sign)
        // throw(Bureaucrat::GradeTooLowException());      
        throw (Form::GradeTooLowException(*this));
    _is_signed = true;
}

/******************* Exception class ************/

Form::GradeTooHighException::GradeTooHighException(const Form& doc) : _doc(doc)
{    
    _error = "Form: " + _doc.getName() + ": grade too high";
}

const char* Form::GradeTooHighException::what() const throw()
{
    // return (_error.c_str());
    return ("Grade too high");
}

Form::GradeTooLowException::GradeTooLowException(const Form& doc) : _doc(doc)
{
    _error = "Form: " + _doc.getName() + ": grade too low";
}

// what() is  const --> so can't build _error message here
// so need to build _error in the constructor
const char* Form::GradeTooLowException::what() const throw() 
{   
    //return (_error.c_str());
    return ("Grade too low");
}



// Explanation

// Store the Message:
// In the constructor, construct the error message using doc->getName().
// Store it in a member variable _message of type std::string.
// _message is guaranteed to outlive the what() call because it is a member of the exception object.

// Return the Stored Message:
// In what(), return _message.c_str(). Since _message is a member, its lifetime is tied to the exception object,
//  and the pointer remains valid as long as the exception object exists.

// Why This Works
// By storing the constructed error message in _message, you avoid relying on temporary objects.
// The std::string ensures proper memory management, and c_str() now points to a valid internal buffer of _message.

/* draft */
// _error.append((*_doc).getName());    
// // return ("Grade too low"); --> ok
// return (("toto" + (*_doc)._name).c_str()); //--> does NOT work as 

// std::string toto("toto");
// // const char *toto = (std::string("toto") + std::string

// // std::string toto = std::string("toto") ;//+ std::string(_doc._name);
// // std::cout << "ici "<<toto.append(_doc._name) << std::endl;
// // return (("Form: " + _doc.getName() + ": grade too low").c_str());
// // return (std::string("toto") + std::string(_doc._name)).c_str();
// // const char *titi = (toto.append(_doc._name)).c_str();
// // return (std::string("toto").c_str());
// return  ((std::string("erreur") + std::string("toto")).c_str() );
// // return(toto.append(_doc._name).c_str());
// // return("toto");

// throw(Bureaucrat::GradeTooLowException()); 
     