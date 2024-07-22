/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:14:41 by faaraujo          #+#    #+#             */
/*   Updated: 2024/07/22 21:37:06 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* Subject
 *Observe que classes de exceção não precisam ser projetadas em
Forma Canônica Ortodoxa. Mas todas as outras classes precisam.

- Vamos projetar um pesadelo artificial de escritórios, corredores, formulários e filas de espera.
Parece divertido? Não? Que pena.


*/
int	main(void)
{
	{
		Bureaucrat person("Horace Mann", 1);
		
		std::cout << person;
		std::cout << "I tried increment your grade, but..." << std::endl;
		
		try
		{
			person.incrementGrade();
			std::cout << person;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	
	std::cout << "==========================================" << std::endl;
	{
		Bureaucrat person("Otto von Bismarck", 150);
		
		std::cout << person;
		std::cout << "I tried decrement your grade, but..." << std::endl;
		
		try
		{
			person.decrementGrade();
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << "==========================================" << std::endl;
	{
		Bureaucrat person("Alfred P. Sloan Jr", 43);
		
		std::cout << person;
		std::cout << "I tried increment your grade, and..." << std::endl;
		
		try
		{
			person.incrementGrade();
			std::cout << person;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << "==========================================" << std::endl;
	{
		Bureaucrat person;
		
		std::cout << person;
		std::cout << "I tried update your grade, and..." << std::endl;
		
		try
		{
			person.incrementGrade(); // grade take 149
			person.decrementGrade(); // grade take 150
			person.decrementGrade(); // grade try 151 but this is a excepetion
			std::cout << person;
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << "==========================================" << std::endl;
	{
		try
		{
			Bureaucrat person("Somebody", -1);
			std::cout << person;
			std::cout << "I tried update your grade, and..." << std::endl;
			person.incrementGrade();
			std::cout << person;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	
	return (0);
}
