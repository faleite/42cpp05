/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:56:48 by faaraujo          #+#    #+#             */
/*   Updated: 2024/08/15 22:07:46 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/*
Como preencher formulários é chato o suficiente, seria cruel pedir aos nossos 
burocratas para fazer isso o dia todo. Felizmente, os estagiários existem. 
Neste exercício, você tem que implementar a classe Intern. O estagiário não tem 
nome, nem nota, nem características únicas. A única coisa com que os burocratas 
se importam é que eles façam seu trabalho.

No entanto, o estagiário tem uma capacidade importante: a função makeForm(). 
Ela pega duas strings. A primeira é o nome de um formulário e a segunda é o 
alvo do formulário. Ela retorna um ponteiro para um objeto Form 
(cujo nome é o passado como parâmetro) cujo alvo será inicializado para 
o segundo parâmetro.

Ela imprimirá algo como:

Intern cria <form>

Se o nome do formulário passado como parâmetro não existir, 
imprima uma mensagem de erro explícita.

Você deve evitar soluções ilegíveis e feias como usar uma floresta 
if/elseif/else. Esse tipo de coisa não será aceito durante o processo de 
avaliação. Você não está mais em Piscine (pool). Como de costume, 
você tem que testar se tudo funciona como esperado.

Por exemplo, o código abaixo cria um 
RobotomyRequestForm direcionado a "Bender":
*/
class Intern
{
	private:
		std::string _formNames[3];
		// array of function pointers
		AForm* (Intern::*_forms[4])(const std::string &target);
	public:
		class InternExceptions: public AForm::AFormException
		{
			public:
				virtual const char *what() const throw();
		};
		Intern();
		Intern(const Intern &copyObj);
		Intern &operator=(const Intern &assignCopy);
		~Intern();
		
		AForm* makeForm(const std::string &form, const std::string &target);
		// AForm* takeForm(const std::string &form, const std::string &target);
		AForm* makeShrubberyForm(const std::string &target);
		AForm* makeRobotomyForm(const std::string &target);
		AForm* makePresidentialForm(const std::string &target);
		AForm* makeErrorForm(const std::string &target);
};

#endif // INTERN_HPP