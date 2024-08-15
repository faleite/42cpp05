/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:10:20 by faaraujo          #+#    #+#             */
/*   Updated: 2024/08/12 19:14:33 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HHP
# define PRESIDENTIALPARDONFORM_HHP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

#define PRES "PresidentialPardonForm"
#define PRES_SIGN 25
#define PRES_EXEC 5

class Bureaucrat;

/*
PresidentialPardonForm: Notas necessárias: sinal 25, exec 5
Informa que <target> foi perdoado por Zaphod Beeblebrox.
*/
class PresidentialPardonForm: public AForm
{
	private:
		const std::string _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &copyObj);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &assignCopy);
		~PresidentialPardonForm();

		std::string getTarget() const;
		void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &form);

#endif // PRESIDENTIALPARDONFORM_HHP