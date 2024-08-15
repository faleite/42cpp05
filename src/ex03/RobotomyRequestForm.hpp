/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:10:20 by faaraujo          #+#    #+#             */
/*   Updated: 2024/08/12 19:11:04 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HHP
# define ROBOTOMYREQUESTFORM_HHP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

#define ROBOT "RobotomyRequestForm"
#define ROB_SIGN 72
#define ROB_EXEC 45

class Bureaucrat;

/*
Classe concreta:
RobotomyRequestForm: Notas necessárias: sinal 72, exec 45
Faz alguns ruídos de perfuração. Então, informa que <target> 
foi robotomizado com sucesso 50% das vezes. Caso contrário, 
informa que a robotomia falhou.
*/
class RobotomyRequestForm: public AForm
{
	private:
		const std::string _target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &copyObj);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &assignCopy);
		~RobotomyRequestForm();

		std::string getTarget() const;
		void	execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &form);

#endif // ROBOTOMYREQUESTFORM_HHP