/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:30:30 by apaz-mar          #+#    #+#             */
/*   Updated: 2026/01/07 21:38:46 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "Main Form constructor called" << std::endl;
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw (GradeTooHighException());
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw (GradeTooLowException());
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &other)
{
    if(this != &other)
    {
        _isSigned = other._isSigned;
    }
    return (*this);
}

const std::string &Form::getName() const
{
    return (_name);
}

bool Form::isSigned() const
{
    return (_isSigned);
}

int Form::getGradeToSign() const
{
    return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
    return (_gradeToExecute);
}

void Form::beSigned (const Bureaucrat &b)
{
    if (b.getGrade() > _gradeToSign)
        throw (GradeTooLowException());
    _isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
    os << f.getName() << ", form sign grade " << f.getGradeToSign()
        << ", exec grade " << f.getGradeToExecute() << ", signed: " << (f.isSigned() ? "true" : "false") << ".";
    return (os);
}