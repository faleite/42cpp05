/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:56:48 by faaraujo          #+#    #+#             */
/*   Updated: 2024/08/19 19:00:15 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		AForm* makeShrubberyForm(const std::string &target);
		AForm* makeRobotomyForm(const std::string &target);
		AForm* makePresidentialForm(const std::string &target);
		
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
};

#endif // INTERN_HPP