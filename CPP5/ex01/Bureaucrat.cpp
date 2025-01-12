#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade < HIGH)
        throw(Bureaucrat::GradeTooHighException());
    if (grade > LOW)
        throw(Bureaucrat::GradeTooLowException());
    _grade = grade;    
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name)
{
    if (this == &other)
    {
        std::cerr << "Error: Self-copying during construction is undefined." << std::endl;
        return;
    }
    *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this == &other)
        return (*this);
    _grade = other._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    
}

const std::string Bureaucrat::getName() const 
{
    return (_name);
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}

void Bureaucrat::increment()
{    
    if(_grade <= HIGH)
        throw(Bureaucrat::GradeTooHighException());
    else
        _grade--;    
}

void Bureaucrat::decrement()
{
    if(_grade >= LOW)
        throw(Bureaucrat::GradeTooLowException());
    else
        _grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high");    
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}         

std::ostream& operator<<(std::ostream& output, const Bureaucrat& bartleby)
{
    output << bartleby.getName() << ", bureaucrat grade " << bartleby.getGrade() << ".";
    return (output);
}

void Bureaucrat::signForm(Form& doc) const
{
    try
    {
        doc.beSigned(*this);
        std::cout << _name << " signed " << doc.getName() << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << _name << " couldn't sign " << doc.getName();
        std::cout << " because " << e.what() << std::endl; //e of Form::GradeTooLowException
    }  
        
}

// simplist 
// void Bureaucrat::signForm(const Form& doc) const
// {
//     if (_grade > doc.getGradeSign())
//     {         
//     }
//     else  
//         std::cout << _name << " signed " << doc.getName() << std::endl;
// } 