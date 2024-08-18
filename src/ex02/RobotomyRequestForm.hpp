/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:10:20 by faaraujo          #+#    #+#             */
/*   Updated: 2024/08/18 15:17:59 by faaraujo         ###   ########.fr       */
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
RobotomyRequestForm: Required grades: sign 72, exec 45
Makes some drilling noises. Then, informs that <target> 
has been robotomized successfully 50% of the time. Otherwise, 
informs that the robotomy failed.
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