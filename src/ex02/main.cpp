/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:14:41 by faaraujo          #+#    #+#             */
/*   Updated: 2024/08/13 21:31:45 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/*
Em todos os casos, a classe base Form deve ser uma classe abstrata e, portanto, 
deve ser renomeada para AForm. Tenha em mente que os atributos do formulário 
precisam permanecer privados e que eles estão na classe base.

Adicione as seguintes classes concretas:

ShrubberyCreationForm: Notas necessárias: sinal 145, exec 137
Cria um arquivo <target>_shrubbery no diretório de trabalho e grava árvores 
ASCII dentro dele.

RobotomyRequestForm: Notas necessárias: sinal 72, exec 45
Faz alguns ruídos de perfuração. Então, informa que <target> 
foi robotomizado com sucesso 50% das vezes. Caso contrário, 
informa que a robotomia falhou.

PresidentialPardonForm: Notas necessárias: sinal 25, exec 5
Informa que <target> foi perdoado por Zaphod Beeblebrox.

Todos eles recebem apenas um parâmetro em seu construtor: o alvo do formulário. 
Por exemplo, "casa" se você quiser plantar arbustos em casa.

Agora, adicione a função membro execute(Bureaucrat const & executor) const 
ao formulário base e implemente uma função para executar a ação do formulário 
das classes concretas. Você precisa verificar se o formulário está assinado e 
se o grau do burocrata tentando executar o formulário é alto o suficiente. 
Caso contrário, lance uma exceção apropriada.

Se você deseja verificar os requisitos em cada classe concreta ou na classe base 
(e então chamar outra função para executar o formulário) depende de você. 
No entanto, uma maneira é mais bonita do que a outra.

Por fim, adicione a função membro executeForm(AForm const & form) ao Bureaucrat. 
Ela deve tentar executar o formulário. Se for bem-sucedido, imprima algo como:

<bureaucrat> performed <form>

Se não, imprima uma mensagem de erro explícita.
*/
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
