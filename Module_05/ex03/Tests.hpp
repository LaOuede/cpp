/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/02 10:23:46 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TESTS_HPP__
# define __TESTS_HPP__

# include <iostream>
# include <cstdlib>

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "Intern.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

# define C_WHT "\e[0m"
# define C_BOL "\e[1m"
# define C_GRN "\e[32m"
# define C_GRY "\e[90m"

#ifndef EVAL
# define EVAL 0
#endif

# define TITLE(X)	std::cout << C_GRN C_BOL << X << C_WHT << std::endl
# define TEST(X)	std::cout << C_GRY << X << C_WHT << std::endl

void runTests( void ) ;

#endif //------------------------------------------------------------- TESTS.HPP