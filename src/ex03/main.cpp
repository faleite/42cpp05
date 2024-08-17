/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:14:41 by faaraujo          #+#    #+#             */
/*   Updated: 2024/08/17 15:51:01 by faaraujo         ###   ########.fr       */
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
			/* Conversão Dinâmica (dynamic_cast<RobotomyRequestForm *>(rrf)):
			tenta converter rrf para um ponteiro do tipo RobotomyRequestForm*.
			Se a conversão for bem-sucedida, o objeto resultante é tratado como
			um RobotomyRequestForm. A função operator<< específica para RobotomyRequestForm
			será chamada, permitindo a impressão de detalhes específicos dessa classe derivada. */
			// dynamic_cast realiza verificação em tempo de execução e é seguro para hierarquias polimórficas
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
