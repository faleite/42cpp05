/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:10:20 by faaraujo          #+#    #+#             */
/*   Updated: 2024/08/13 21:31:59 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm(ROBOT, ROB_SIGN, ROB_EXEC),
											_target("None")
{
	std::cout << ROBOT << " default constructor called" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
					AForm(ROBOT, ROB_SIGN, ROB_EXEC), _target(target)
{
	std::cout << ROBOT << " parameter constructor called" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copyObj):
										AForm(copyObj), _target(copyObj._target)
{
	std::cout << ROBOT << " copy constructor called" << std::endl;
	if (this != &copyObj)
		*this = copyObj;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &assignCopy)
{
	std::cout << ROBOT << " assignment operator called" << std::endl;
	if (this != &assignCopy)
		AForm::operator=(assignCopy);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << ROBOT << " destructror called" << std::endl;
}
std::string RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	this->beExecuted(executor);
	
	std::cout <<  "crack... crack... ";
	std::srand(std::time(0));
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << _target << " has not been robotomized, the robotomy failed!" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &form)
{
	out << static_cast<const AForm&>(form);
	out << "RobotomyRequestForm target: " << form.getTarget() << std::endl;
	return (out);
}
