/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/03 08:48:39 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN_HPP__
# define __INTERN_HPP__

# include <iostream>

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

# define C_WHT "\e[0m"
# define C_BOL "\e[1m"
# define C_GRN "\e[32m"
# define C_GRY "\e[90m"
# define C_RED "\e[31m"

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::ostream;
using std::string;

class Intern {
	public:
		// Const. & Dest.
		Intern( void ) ;                           //canonical
		Intern( Intern const & rhs ) ;             //canonical
		~Intern( void ) ;                          //canonical

		// Operators overload
		Intern &operator=( Intern const & rhs ) ;  //canonical

		// Functions
		AForm *makeForm( string formName, string formTarget ) ;
		AForm *makeSCF( string target ) ;
		AForm *makeRRF( string target ) ;
		AForm *makePPF( string target ) ;

		// Exceptions
		class BadFormNameInformation : public exception {
			public:
				virtual const char* what() const throw() ;
		};
};

#endif