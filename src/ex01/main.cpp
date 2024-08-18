/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:14:41 by faaraujo          #+#    #+#             */
/*   Updated: 2024/08/18 14:52:11 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << "==========================================" << std::endl;
	{
		try
		{
			Form form("Performance evaluation", 5, 42);
			Bureaucrat a("Horace Mann", 5);
			Bureaucrat b("Otto Von Bismarck", 5);
			std::cout << "==========================================" << std::endl;
			std::cout << a;
			std::cout << b;
			std::cout << "==========================================" << std::endl;
			std::cout << form;
			try
			{
				
				std::cout << "==========================================" << std::endl;
				std::cout << "I tried update " << a.getName() << "'s grade and..." << std::endl;
				a.decrementGrade();
				std::cout << a;
				a.signForm(form);
				b.signForm(form);
				// form.beSigned(b);
				try
				{
					form.beSigned(b);
				}
				catch(const std::exception& e)
				{
					std::cerr << "===========plus  inner exception==========" << std::endl;
					std::cerr << form.getName() << " " << e.what() << std::endl;
				}
				std::cout << "==========================================" << std::endl;
			}
			catch (std::exception &e)
			{
				std::cerr << "=============inner exception==============" << std::endl;
				std::cerr << e.what() << std::endl;
			}
		}
		catch (std::exception &e)
		{
			std::cerr << "=============outer exception==============" << std::endl;
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}
