/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:10:20 by faaraujo          #+#    #+#             */
/*   Updated: 2024/08/18 15:15:39 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
						AForm(PRES, PRES_SIGN, PRES_EXEC), _target("None")
												
{
	std::cout << PRES << " default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):
						AForm(PRES, PRES_SIGN, PRES_EXEC), _target(target)
{
	std::cout << PRES << " parameter constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copyObj):
						AForm(copyObj), _target(copyObj._target)
{
	std::cout << PRES << " copy constructor called" << std::endl;
	if (this != &copyObj)
		*this = copyObj;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &assignCopy)
{
	std::cout << PRES << " assignment operator called" << std::endl;
	if (this != &assignCopy)
		AForm::operator=(assignCopy);
	return (*this); 
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << PRES << " destructror called" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
	return (_target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	this->beExecuted(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &form)
{
	/* static_cast does not perform runtime checking and is faster, 
	but the programmer must ensure the safety of the cast. */
	out << static_cast<const AForm&>(form);
	out << "PresidentialPardonForm target: " << form.getTarget() << std::endl;
	return (out);
}
