/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:10:20 by faaraujo          #+#    #+#             */
/*   Updated: 2024/08/12 18:13:50 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm(SHRU, SHRU_SIGN, SHRU_EXEC),
												_target("None")
{
	std::cout << SHRU << " default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): 
					AForm(SHRU, SHRU_SIGN, SHRU_EXEC), _target(target)
{
	std::cout << SHRU << " parameter constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copyObj):
											AForm(copyObj), _target(copyObj._target) 
{
	std::cout << SHRU << " copy constructor called" << std::endl;
	if (this != &copyObj)
		*this = copyObj;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assignCopy)
{
	std::cout << SHRU << " assignment operator called" << std::endl;
	if (this != &assignCopy)
		AForm::operator=(assignCopy);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << SHRU << " destructror called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

// Exception
const char *ShrubberyCreationForm::ShrubberyException::what() const throw()
{
	return ("Failed to create file to ShrubberyCreationForm");
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	this->beExecuted(executor);
	std::ofstream file((_target + "_shrubbery").c_str());
	if (file.fail())
		throw ShrubberyException();
	file << "	      .     .  .      +     .      .          ." << "\n" \
	<< "     .       .      .     #       .           ." << "\n" \
	<< "        .      .         ###            .      .      ." << "\n" \
	<< "      .      .   '#:. .:##'##:. .:#'  .      ." << "\n" \
	<< "          .      . '####'###'####'  ." << "\n" \
	<< "       .     '#:.    .:#'###'#:.    .:#'  .        .       ." << "\n" \
	<< "  .             '#########'#########'        .        ." << "\n" \
	<< "        .    '#:.  '####'###'####'  .:#'   .       ." << "\n" \
	<< "     .     .  '#######''##'##''#######'                  ." << "\n" \
	<< "                .'##'#####'#####'##'           .      ." << "\n" \
	<< "    .   '#:. ...  .:##'###'###'##:.  ... .:#'     ." << "\n" \
	<< "      .     '#######'##'#####'##'#######'      .     ." << "\n" \
	<< "    .    .     '#####''#######''#####'    .      ." << "\n" \
	<< "            .     '      000      '    .     ." << "\n" \
	<< "       .         .   .   000     .        .       ." << "\n" \
	<< ".. .. ..................O000O........................ ...... ..." << std::endl;
	file.close();
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &form)
{
	// const AForm *AFormOperator;
	
	/* AFormOperator é um ponteiro para a classe base AForm, mas está apontando para
	um objeto da classe derivada ShrubberyCreationForm. */
	// AFormOperator = &form;
	// out << *AFormOperator;

	/* Converte explicitamente o objeto form (que é do tipo ShrubberyCreationForm) 
	para uma referência constante (const AForm&) da classe base AForm. */
	out << static_cast<const AForm&>(form);
	out << "ShrubberyCreationForm target: " << form.getTarget() << std::endl;
	return (out);
}
