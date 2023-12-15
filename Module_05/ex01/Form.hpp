/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/03 12:43:57 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_HPP__
# define __FORM_HPP__

# include <iostream>
# include "Bureaucrat.hpp"

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

class Bureaucrat;

class Form {
	public:
		// Const. & Dest.
		Form( void ) ;                                              //canonical
		Form( string name, int toSign, int toExec ) ;
		Form( Form const & rhs ) ;                                  //canonical
		~Form( void ) ;                                             //canonical

		// Operators overload
		Form &operator=( Form const & rhs ) ;                       //canonical

		// Getters & Setters
		string const &getName( void ) const ;
		bool const &getSigned( void ) const ;
		int const &getGradeToSign( void ) const ;
		int const &getGradeToExec( void ) const ;

		// Functions
		void beSigned( Bureaucrat &bur ) ;

		// Exceptions
		class GradeTooHighException : public exception {
			public:
				virtual const char* what() const throw() ;
		};

		class GradeTooLowException : public exception {
			public:
				virtual const char* what() const throw() ;
		};

		class AlreadySignedException : public exception {
			public:
				virtual const char* what() const throw() ;
		};

	private:
		// Attributes
		string const _name;
		bool _signed;
		int const _gradeToSign;
		int const _gradeToExec;
};

// Overload operator <<
ostream &operator<<( ostream &o, Form const & rhs ) ;

#endif