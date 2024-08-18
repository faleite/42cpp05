/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:14:41 by faaraujo          #+#    #+#             */
/*   Updated: 2024/08/18 16:07:49 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	std::cout << "=================Subject Test==================" << std::endl;
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		
		if (rrf)
		{
			/* Dynamic Cast (dynamic_cast<RobotomyRequestForm *>(rrf)):
			attempts to cast rrf to a pointer of type RobotomyRequestForm*.
			If the cast is successful, the resulting object is treated as
			a RobotomyRequestForm. The operator<< function specific to RobotomyRequestForm
			will be called, allowing printing of details specific to that derived class. */
			// dynamic_cast performs runtime checking and is safe for polymorphic hierarchies
			std::cout << *dynamic_cast<RobotomyRequestForm*>(rrf);
			delete (rrf);
		}
	}
	std::cout << "==============Non-existent form===================" << std::endl;
	{
		Intern someRandomIntern;
		AForm* rrf;
		
		rrf = someRandomIntern.makeForm("day off", "silva");
		if (rrf)
			delete rrf;
	}
	std::cout << "===============Shrubbery form================" << std::endl;
	{
		try
		{
			Intern someRandomIntern;
			AForm* rrf;
			Bureaucrat b("john", 1);

			rrf = someRandomIntern.makeForm("shrubbery creation", "jorge");
			if (rrf)
			{
				b.signForm(*rrf);
				b.executeForm(*rrf);
				std::cout << *dynamic_cast<ShrubberyCreationForm*>(rrf);
				delete rrf;
			}
		}
		catch (const std::exception& e)
		{
			std::cerr << "=============exception==============" << std::endl;
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "===============Robotomy form================" << std::endl;
	{
		try
		{
			Intern someRandomIntern;
			AForm* rrf;
			Bureaucrat b("john", 1);

			rrf = someRandomIntern.makeForm("robotomy request", "jorge");
			if (rrf)
			{
				b.signForm(*rrf);
				b.executeForm(*rrf);
				std::cout << *dynamic_cast<RobotomyRequestForm*>(rrf);
				delete rrf;
			}
		}
		catch (const std::exception& e)
		{
			std::cerr << "=============exception==============" << std::endl;
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "==================Presidential form====================" << std::endl;
	{
		try
		{
			Intern someRandomIntern;
			AForm* rrf;
			Bureaucrat b("john", 1);

			rrf = someRandomIntern.makeForm("presidential pardon", "jorge");
			if (rrf)
			{
				b.signForm(*rrf);
				b.executeForm(*rrf);
				std::cout << *dynamic_cast<PresidentialPardonForm *>(rrf);
				delete rrf;
			}
		}
		catch (const std::exception& e)
		{
			std::cerr << "=============exception==============" << std::endl;
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}
