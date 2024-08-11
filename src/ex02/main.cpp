/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:14:41 by faaraujo          #+#    #+#             */
/*   Updated: 2024/08/11 18:12:47 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/*
      .     .  .      +     .      .          .
     .       .      .     #       .           .
        .      .         ###            .      .      .
      .      .   "#:. .:##"##:. .:#"  .      .
          .      . "####"###"####"  .
       .     "#:.    .:#"###"#:.    .:#"  .        .       .
  .             "#########"#########"        .        .
        .    "#:.  "####"###"####"  .:#"   .       .
     .     .  "#######""##"##""#######"                  .
                ."##"#####"#####"##"           .      .
    .   "#:. ...  .:##"###"###"##:.  ... .:#"     .
      .     "#######"##"#####"##"#######"      .     .
    .    .     "#####""#######""#####"    .      .
            .     "      000      "    .     .
       .         .   .   000     .        .       .
.. .. ..................O000O........................ ...... ...
*/

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
