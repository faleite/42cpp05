/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:32:00 by faaraujo          #+#    #+#             */
/*   Updated: 2024/08/12 16:22:00 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Canonical members

Form::Form(): _name("None"), _isSigned(false), 
			_gradeToSign(GRADE_MIN), _gradeToExec(GRADE_MIN)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string &name, const int grdToSig, const int grdToEx): 
	_name(name), _isSigned(false), _gradeToSign(grdToSig), _gradeToExec(grdToEx)
{
	std::cout << "Form constructor called for ";
	std::cout << this->_name << std::endl;
	
	if (grdToSig < GRADE_MAX || grdToEx < GRADE_MAX)
		throw GradeTooHighException();
	if (grdToSig > GRADE_MIN || grdToEx > GRADE_MIN)
		throw GradeTooLowException();
}

Form::Form(const Form &copyObj): _name(copyObj._name), _isSigned(copyObj._isSigned),
	_gradeToSign(copyObj._gradeToSign), _gradeToExec(copyObj._gradeToExec)
{
	std::cout << "Form copy constructor called" << std::endl;
	if (this != &copyObj)
		*this = copyObj;
}
Form &Form::operator=(const Form &assignCopy)
{
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &assignCopy)
		this->_isSigned = assignCopy._isSigned;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destructor called for ";
	std::cout << this->_name << std::endl;
}

// Exceptions

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form grade too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form grade too low!");
}
const char *Form::FormException::what() const throw()
{
	return ("Form has already been signed");
}

// Getters

std::string Form::getName() const
{
	return (_name);
}

int	Form::getGradeToSign() const
{
	return (_gradeToSign);	
}

int	Form::getGradeToExec() const
{
	return (_gradeToExec);
}

bool	Form::getIsSigned() const
{
	return (_isSigned);
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << form.getName() << " form status:\n"
	<< "Grade required to sign: " << form.getGradeToSign() << "\n"
	<< "Grade required to execute: " << form.getGradeToExec() << "\n"
	<< "Form signature status: " 
	<< (form.getIsSigned() ? "Signed" : "Unsigned") << std::endl;
	return (out);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (_isSigned)
		throw Form::FormException();
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_isSigned = true; 
}
