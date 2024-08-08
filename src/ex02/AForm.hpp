/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 21:06:55 by faaraujo          #+#    #+#             */
/*   Updated: 2024/07/31 20:06:22 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

/*
Agora que você tem burocratas, vamos dar a eles algo para fazer. Que atividade 
melhor poderia haver do que preencher uma pilha de formulários?

Então, vamos fazer uma classe Form. Ela tem:
Um nome constante.
Um booleano indicando se ele é assinado (na construção, não é).
Uma nota constante necessária para assiná-lo.
E uma nota constante necessária para executá-lo.

Todos esses atributos são privados, não protegidos.

As notas do Form seguem as mesmas regras que se aplicam ao Bureaucrat. 
Assim, as seguintes exceções serão lançadas se uma nota do form estiver fora 
dos limites: Form::GradeTooHighException e Form::GradeTooLowException.

Da mesma forma que antes, escreva getters para todos os atributos e uma 
sobrecarga do operador de inserção («) que imprime todas as informações do form.

Adicione também uma função membro beSigned() ao Form que recebe um Burocrata 
como parâmetro. Ela altera o status do formulário para assinado se a nota do 
burocrata for alta o suficiente (maior ou igual à exigida). Lembre-se, a nota 
1 é maior que a nota 2.
Se a nota for muito baixa, lance um Form::GradeTooLowException.

Por fim, adicione uma função membro signForm() ao Burocrata. Se o formulário 
for assinado, ele imprimirá algo como:
<bureaucrat> signed <form>
Caso contrário, ele imprimirá algo como:
<bureaucrat> couldn’t sign <form> because <reason>.

Implemente e entregue alguns testes para garantir que tudo funcione 
conforme o esperado.
*/
class AForm
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExec;
	public:
		// Exceptions
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();	
		};
		
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();		
		};

		class AFormException: public std::exception
		{
			public:
				virtual const char *what() const throw();		
		};
		
		// Canonical AForm
		AForm();
		AForm(const std::string &name, 
			const int grdToSig, const int grdToEx);
		AForm(const AForm &copyObj);
		AForm &operator=(const AForm &assignCopy);
		virtual ~AForm();

		std::string getName() const;
		bool	getIsSigned() const;
		int	getGradeToSign() const;
		int	getGradeToExec() const;
		void beSigned(const Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif // AFORM_HPP