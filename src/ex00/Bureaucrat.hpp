/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:49:40 by faaraujo          #+#    #+#             */
/*   Updated: 2024/07/19 20:35:28 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT
# define BUREAUCRAT

#include <exception>
#include <iostream>

#define GRADE_MIN 150
#define GRADE_MAX 1

class Bureaucrat
{
	private:
		const std::string _name;
		unsigned short int _grade;
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
		
		// Canonical Form
		Bureaucrat();
		Bureaucrat(const std::string &name, unsigned short int grade);
		Bureaucrat(const Bureaucrat &copyObj);
		Bureaucrat &operator=(const Bureaucrat &assignCopy);
		~Bureaucrat();
		
		std::string getName() const;
		unsigned short int getGrade() const;
		void incrementGrade();
		void decrementGrade();
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &gay);

#endif // BUREAUCRAT