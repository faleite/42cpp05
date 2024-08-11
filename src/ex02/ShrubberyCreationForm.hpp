/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:10:20 by faaraujo          #+#    #+#             */
/*   Updated: 2024/08/11 17:55:17 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HHP
# define SHRUBBERYCREATIONFORM_HHP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

#define SHRU_SIGN 145
#define SHRU_EXEC 137

class Bureaucrat;

/*
Classe concreta:
ShrubberyCreationForm: Notas necessárias: sinal 145, exec 137
Cria um arquivo <target>_shrubbery no diretório de trabalho e grava árvores 
ASCII dentro dele.
*/
class ShrubberyCreationForm: public AForm
{
	private:
		const std::string _target;
	public:
		// Exceptions
		class ShrubberyException: public std::exception
		{
			public:
				virtual const char *what() const throw();	
		};
		// Canonical form
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copyObj);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &assignCopy);
		~ShrubberyCreationForm();

		std::string getTarget() const;
		void	execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &form);

#endif // SHRUBBERYCREATIONFORM_HHP