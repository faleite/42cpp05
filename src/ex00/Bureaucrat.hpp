/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:49:40 by faaraujo          #+#    #+#             */
/*   Updated: 2024/07/18 20:24:01 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT
# define BUREAUCRAT

#include <exception>
#include <iostream>
// #include <stdexcept>

class Bureaucrat: public std::exception
{
	private:
		const std::string name;
		unsigned short int grade;
	public:
		const char* what() const throw();
		void GradeTooHighException();
		void GradeTooLowException();
		std::string getName(const std::string &name);
		unsigned short int getGrade();
		void setName(const std::string &name);
		void setGrade();
};

#endif // BUREAUCRAT