/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:56:48 by faaraujo          #+#    #+#             */
/*   Updated: 2024/08/17 14:52:43 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
	
	_formNames[0] = "shrubbery creation";
    _formNames[1] = "robotomy request";
    _formNames[2] = "presidential pardon";

    _forms[0] = &Intern::makeShrubberyForm;
    _forms[1] = &Intern::makeRobotomyForm;
    _forms[2] = &Intern::makePresidentialForm;
}
Intern::Intern(const Intern &copyObj)
{
	std::cout << "Intern copy constructor called" << std::endl;
	(void)copyObj;
}

Intern &Intern::operator=(const Intern &assignCopy)
{
	std::cout << "Intern assignment operator called" << std::endl;
	(void)assignCopy;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

const char *Intern::InternExceptions::what() const throw()
{
	return ("form doesn’t exist");
}

AForm* Intern::makeShrubberyForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeRobotomyForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makePresidentialForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string &form, const std::string &target)
{	
	AForm *newForm(NULL);
	int i(0);
	
	try
	{
		while (i < 3 && this->_formNames[i].compare(form) != 0)
			i++;
		if (i > 2)
			throw InternExceptions();
		newForm = (this->*_forms[i])(target);
		std::cout << "Intern creates " << newForm->getName() << std::endl;
		return (newForm);
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const AForm::AFormException& e)
	{
		std::cerr << "Intern didn't create form " << form;
		std::cerr << " because " << e.what() << std::endl;
	}
	return (0);
}
