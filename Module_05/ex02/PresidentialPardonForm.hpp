/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/02 15:28:32 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRESIDENTIALPARDONFORM_HPP__
# define __PRESIDENTIALPARDONFORM_HPP__

# include <iostream>
# include <fstream>
# include "AForm.hpp"

# define MIN_GRADE_SIGN_PRES 25
# define MIN_GRADE_EXEC_PRES 5

# define C_WHT "\e[0m"
# define C_BOL "\e[1m"
# define C_CYA "\e[36m"
# define C_GRN "\e[32m"
# define C_GRY "\e[90m"
# define C_RED "\e[31m"

class PresidentialPardonForm : public AForm {
	public:
		// Const. & Dest.
		PresidentialPardonForm( void ) ;                                           //canonical
		PresidentialPardonForm( string target ) ;
		PresidentialPardonForm( PresidentialPardonForm const & rhs ) ;             //canonical
		~PresidentialPardonForm( void ) ;                                          //canonical

		// Operators overload
		PresidentialPardonForm &operator=( PresidentialPardonForm const & rhs ) ;  //canonical

		// Getters & Setters
		string const &getTarget( void ) const ;

		// Functions
		void execute( Bureaucrat const &executor ) const ;

	private:
		// Attributes
		string _target;
};

// Overload operator <<
ostream &operator<<( ostream &o, PresidentialPardonForm const & rhs ) ;

#endif