/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:14:41 by faaraujo          #+#    #+#             */
/*   Updated: 2024/07/25 20:56:34 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/**
 * Temos um Burocrata e um formulario
 * Acho que a ideia e fazer o burocrata preencher o formulario
 * 1. cria um formulario
 *   - possui Nome, notaAss, NotaExec, Ass: s/n
 * 2. Burocrata preenche o formulario
 */
int	main(void)
{
	std::cout << "==========================================" << std::endl;
	{
		try
		{
			Form form("Performance evaluation", 5, 42);
			Bureaucrat a("Horace Mann", 5);
			Bureaucrat b("Otto von Bismarck", 5);
			std::cout << "==========================================" << std::endl;
			std::cout << a;
			std::cout << b;
			std::cout << "==========================================" << std::endl;
			std::cout << form;
			std::cout << "==========================================" << std::endl;
			form.beSigned(b);
			std::cout << "I tried update " << a.getName() << "'s grade and..." << std::endl;
			try
			{
				
				a.decrementGrade();
				std::cout << a;
				a.signForm(form);
				b.signForm(form);
				std::cout << "==========================================" << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << "Caught an inner exception:" << std::endl;
				std::cerr << e.what() << std::endl;
			}
		}
		catch (std::exception &e)
		{
			std::cout << "Caught an outer exception:" << std::endl;
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}
