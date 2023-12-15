/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/12/01 12:00:17 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TESTS_HPP__
# define __TESTS_HPP__

# include <array>
# include <deque>
# include <iostream>
# include <list>
# include <vector>


#include "easyfind.hpp"

using std::array;
using std::cerr;
using std::cout;
using std::deque;
using std::endl;
using std::list;
using std::string;
using std::vector;

# define C_BOL "\e[1m"
# define C_BLU "\e[34m"
# define C_GRN "\e[32m"
# define C_GRY "\e[90m"
# define C_WHT "\e[0m"

# define TITLE(X)	std::cout << C_GRN C_BOL << X << C_WHT << std::endl
# define TEST(X)	std::cout << C_GRY << X << C_WHT << std::endl

void runTests( void ) ;

#endif //------------------------------------------------------------- TESTS.HPP