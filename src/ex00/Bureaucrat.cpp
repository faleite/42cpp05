/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:49:40 by faaraujo          #+#    #+#             */
/*   Updated: 2024/07/22 21:30:41 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Canonical members

Bureaucrat::Bureaucrat(): _name("None"), _grade(GRADE_MIN)
{
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade):
	_name(name), _grade(grade)
{
	std::cout << "Constructor called for ";
	std::cout << this->_name << std::endl;
	
	if (grade < GRADE_MAX) 
        throw GradeTooHighException();
	else if (grade > GRADE_MIN) 
        throw GradeTooLowException();
}

/*
O construtor de cópia permite copyObj._name na lista de inicializadores de membros
porque this->name ainda não foi inicializado.

A atribuição de cópia, this->_name já foi inicializada e const
não pode ser copiada
 */
Bureaucrat::Bureaucrat(const Bureaucrat &copyObj):
						_name(copyObj._name), _grade(copyObj._grade)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &copyObj)
		*this = copyObj;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &assignCopy)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &assignCopy)
		this->_grade = assignCopy._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called for ";
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
	if (_grade + 1 > GRADE_MAX)
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
