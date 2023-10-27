/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/23 19:04:06 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TESTS_HPP__
# define __TESTS_HPP__

# include <iostream>
# include <cstdlib>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

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