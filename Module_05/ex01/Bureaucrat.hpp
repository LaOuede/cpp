/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/03 08:56:59 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_HPP__
# define __BUREAUCRAT_HPP__

# include <iostream>
# include "Form.hpp"

# define MIN_GRADE 150
# define MAX_GRADE 1

# define C_WHT "\e[0m"
# define C_BOL "\e[1m"
# define C_CYA "\e[36m"
# define C_GRN "\e[32m"
# define C_GRY "\e[90m"
# define C_RED "\e[31m"

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::ostream;
using std::string;

class Form;

class Bureaucrat {
	public:
		// Const. & Dest.
		Bureaucrat( void ) ;                               //canonical
		Bureaucrat( string const name, int grade ) ;
		Bureaucrat( Bureaucrat const & rhs ) ;             //canonical
		~Bureaucrat( void ) ;                              //canonical

		// Operators overload
		Bureaucrat &operator=( Bureaucrat const & rhs );  //canonical

		// Getters & Setters
		string const &getName( void ) const ;
		int const &getGrade( void ) const ;

		// Functions
		void incrementGrade( void ) ;
		void decrementGrade( void ) ;
		void signForm( Form &form ) ;

		// Exceptions
		class GradeTooHighException : public exception {
			public:
				virtual const char* what() const throw() ;
		};

		class GradeTooLowException : public exception {
			public:
				virtual const char* what() const throw() ;
		};

	private:
		// Attributes
		string const _name;
		int _grade;
};

// (<<) overload operator
ostream &operator<<( ostream & o, Bureaucrat const & rhs );

#endif