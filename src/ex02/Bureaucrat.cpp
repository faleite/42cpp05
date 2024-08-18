/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:49:40 by faaraujo          #+#    #+#             */
/*   Updated: 2024/08/18 14:58:05 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Canonical members

Bureaucrat::Bureaucrat(): _name("None"), _grade(GRADE_MIN)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade):
	_name(name), _grade(grade)
{
	std::cout << "Bureaucrat constructor called for ";
	std::cout << this->_name << std::endl;
	
	if (grade < GRADE_MAX) 
        throw GradeTooHighException();
	else if (grade > GRADE_MIN) 
        throw GradeTooLowException();
}

/*
The copy constructor allows copyObj._name in the member initializer list 
because this->name is not yet initialized.

In the copy assignment, this->_name is already initialized and 
const cannot be copied
 */
Bureaucrat::Bureaucrat(const Bureaucrat &copyObj):
						_name(copyObj._name), _grade(copyObj._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	if (this != &copyObj)
		*this = copyObj;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &assignCopy)
{
	std::cout << "Bureaucrat assignment operator called" << std::endl;
	if (this != &assignCopy)
		this->_grade = assignCopy._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called for ";
	std::cout << this->_name << std::endl;
}

// Member functions

std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < GRADE_MAX)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > GRADE_MIN)
		throw GradeTooLowException();
	_grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &gay)
{
	out << gay.getName() << ", bureaucrat grade " << gay.getGrade() << ".\n";
	return (out);
}

// Exceptions

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high, the max of grade is 1");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low, the min of grade is 150");
}

// About form

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch(const AForm::AFormException& e)
	{
		std::cerr << _name << " couldn't sign " << form.getName();
		std::cerr << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch(const AForm::AFormException& e)
	{
		std::cerr << _name << " cannot execute " << form.getName();
		std::cerr << " becauase " << e.what() << '\n';
	}
}
