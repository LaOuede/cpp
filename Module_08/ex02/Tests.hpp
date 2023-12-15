/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/30 11:32:10 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TESTS_HPP__
# define __TESTS_HPP__

# include <deque>
# include <iostream>
# include <list>
# include <string>
# include <vector>


# include "MutantStack.hpp"

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