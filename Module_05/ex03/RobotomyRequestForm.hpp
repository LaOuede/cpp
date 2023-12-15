/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/02 15:07:30 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ROBOTOMYREQUESTFORM_HPP__
# define __ROBOTOMYREQUESTFORM_HPP__

# include <iostream>
# include <fstream>
# include "AForm.hpp"

# define MIN_GRADE_SIGN_ROB 72
# define MIN_GRADE_EXEC_ROB 45

# define C_WHT "\e[0m"
# define C_BOL "\e[1m"
# define C_CYA "\e[36m"
# define C_GRN "\e[32m"
# define C_GRY "\e[90m"
# define C_RED "\e[31m"

class RobotomyRequestForm : public AForm {
	public:
		// Const. & Dest.
		RobotomyRequestForm( void ) ;                                        //canonical
		RobotomyRequestForm( string target ) ;
		RobotomyRequestForm( RobotomyRequestForm const & rhs ) ;             //canonical
		~RobotomyRequestForm( void ) ;                                       //canonical

		// Operators overload
		RobotomyRequestForm &operator=( RobotomyRequestForm const & rhs ) ;  //canonical

		// Getters & Setters
		string const &getTarget( void ) const ;

		// Functions
		void execute( Bureaucrat const &executor ) const ;

	private:
		// Attributes
		string _target;
};

// Overload operator <<
ostream &operator<<( ostream &o, RobotomyRequestForm const & rhs ) ;

#endif