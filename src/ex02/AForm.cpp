/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:32:00 by faaraujo          #+#    #+#             */
/*   Updated: 2024/08/13 21:32:23 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Canonical members

AForm::AForm(): _name("None"), _isSigned(false), 
			_gradeToSign(GRADE_MIN), _gradeToExec(GRADE_MIN)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string &name, const int grdToSig, const int grdToEx): 
	_name(name), _isSigned(false), _gradeToSign(grdToSig), _gradeToExec(grdToEx)
{
	std::cout << "AForm constructor called for ";
	std::cout << this->_name << std::endl;
	
	if (grdToSig < GRADE_MAX || grdToEx < GRADE_MAX)
		throw GradeTooHighException();
	if (grdToSig > GRADE_MIN || grdToEx > GRADE_MIN)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &copyObj): _name(copyObj._name), _isSigned(copyObj._isSigned),
	_gradeToSign(copyObj._gradeToSign), _gradeToExec(copyObj._gradeToExec)
{
	std::cout << "AForm copy constructor called" << std::endl;
	if (this != &copyObj)
		*this = copyObj;
}
AForm &AForm::operator=(const AForm &assignCopy)
{
	std::cout << "AForm assignment operator called" << std::endl;
	if (this != &assignCopy)
		this->_isSigned = assignCopy._isSigned;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm destructor called for ";
	std::cout << this->_name << std::endl;
}

// Exceptions

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("grade too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("grade too low!");
}
const char *AForm::AFormSigned::what() const throw()
{
	return ("has already been signed");
}

const char *AForm::AFormNotSigned::what() const throw()
{
	return ("has not been signed");
}

// Getters

std::string AForm::getName() const
{
	return (_name);
}

int	AForm::getGradeToSign() const
{
	return (_gradeToSign);	
}

int	AForm::getGradeToExec() const
{
	return (_gradeToExec);
}

bool	AForm::getIsSigned() const
{
	return (_isSigned);
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << form.getName() << " form status:\n"
	<< "Grade required to sign: " << form.getGradeToSign() << "\n"
	<< "Grade required to execute: " << form.getGradeToExec() << "\n"
	<< "Form signature status: " 
	<< (form.getIsSigned() ? "Signed" : "Unsigned") << std::endl;
	return (out);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (_isSigned)
		throw AForm::AFormSigned();
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_isSigned = true; 
}

void AForm::beExecuted(const Bureaucrat &bureaucrat) const
{
	if (!_isSigned)
		throw AForm::AFormNotSigned();
	if (bureaucrat.getGrade() > _gradeToExec)
		throw AForm::GradeTooLowException();
}
