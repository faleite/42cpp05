/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 21:06:55 by faaraujo          #+#    #+#             */
/*   Updated: 2024/08/12 17:37:43 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

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

		class AFormNotSigned: public std::exception
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
		void beExecuted(const Bureaucrat &bureaucrat) const;
		virtual void	execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif // AFORM_HPP