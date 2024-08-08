/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:10:20 by faaraujo          #+#    #+#             */
/*   Updated: 2024/07/31 20:13:00 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ShrubberyCreationForm.HHP
# define ShrubberyCreationForm.HHP

#include "Bureaucrat.hpp"

/*
Classe concreta:
ShrubberyCreationForm: Notas necessárias: sinal 145, exec 137
Cria um arquivo <target>_shrubbery no diretório de trabalho e grava árvores 
ASCII dentro dele.

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

#endif // ShrubberyCreationForm.HHP