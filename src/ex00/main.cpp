/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:14:41 by faaraujo          #+#    #+#             */
/*   Updated: 2024/07/19 20:42:04 by faaraujo         ###   ########.fr       */
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
		// Bureaucrat person("Horace Mann", 1);
		Bureaucrat person;
		
		std::cout << person;
		std::cout << "I tried increment your grade, but..." << std::endl;
		
		try
		{
			person.incrementGrade();
			std::cout << person;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
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
			std::cout << e.what() << std::endl;
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
			std::cout << e.what() << std::endl;
		}
	}

	return (0);
}
