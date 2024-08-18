/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:14:41 by faaraujo          #+#    #+#             */
/*   Updated: 2024/08/18 15:30:14 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::cout << "=============ShrubberyCreation================" << std::endl;
	{
		try
		{
			ShrubberyCreationForm form("garden");
			Bureaucrat a("Peter", 137);
			std::cout << "==========================================" << std::endl;
			a.signForm(form);
			a.executeForm(form);
			std::cout << form;
			std::cout << a;
			std::cout << "==========================================" << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << "=============exception==============" << std::endl;
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "\n===============RobotomyRequestForm==================" << std::endl;
	{
		try
		{
			RobotomyRequestForm form("documents");
			Bureaucrat a("John", 45);
			std::cout << "==========================================" << std::endl;
			a.signForm(form);
			a.executeForm(form);
			std::cout << form;
			std::cout << a;
			std::cout << "==========================================" << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << "=============exception==============" << std::endl;
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "\n==============PresidentialPardonForm================" << std::endl;
	{
		try
		{
			PresidentialPardonForm form("Manager");
			Bureaucrat a("Bruce", 5);
			std::cout << "==========================================" << std::endl;
			a.executeForm(form);
			a.signForm(form);
			a.executeForm(form);
			std::cout << form;
			std::cout << a;
			std::cout << "==========================================" << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << "=============exception==============" << std::endl;
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "==========================================" << std::endl;
	return (0);
}
