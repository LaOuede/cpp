/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/02 15:07:38 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHRUBBERYCREATIONFORM_HPP__
# define __SHRUBBERYCREATIONFORM_HPP__

# include <iostream>
# include <fstream>
# include "AForm.hpp"

# define MIN_GRADE_SIGN_SHR 145
# define MIN_GRADE_EXEC_SHR 137

# define C_WHT "\e[0m"
# define C_BOL "\e[1m"
# define C_CYA "\e[36m"
# define C_GRN "\e[32m"
# define C_GRY "\e[90m"
# define C_RED "\e[31m"

# define ASCII_TREES "\
               ,@@@@@@@,\n\
       ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n\
   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n\
   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n\
   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n\
   `&%\\ ` /%&'    |.|        \\ '|8'\n\
       |o|        | |         | |\n\
       |.|        | |         | |\n\
  \\/ ._\\///_/__/  ,\\_//__\\/.  \\_//__/_\n\
"

using std::ofstream;

class ShrubberyCreationForm : public AForm {
	public:
		// Const. & Dest.
		ShrubberyCreationForm( void ) ;                                              //canonical
		ShrubberyCreationForm( string target ) ;
		ShrubberyCreationForm( ShrubberyCreationForm const & rhs ) ;                 //canonical
		~ShrubberyCreationForm( void ) ;                                             //canonical

		// Operators overload
		ShrubberyCreationForm &operator=( ShrubberyCreationForm const & rhs ) ;  //canonical

		// Getters & Setters
		string const &getTarget( void ) const ;

		// Functions
		void execute( Bureaucrat const &executor ) const ;

	private:
		// Attributes
		string _target;
};

// Overload operator <<
ostream &operator<<( ostream &o, ShrubberyCreationForm const & rhs ) ;

#endif