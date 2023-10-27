/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/15 20:17:45 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TESTS_HPP__
# define __TESTS_HPP__

# include <iostream>

# define C_WHT "\e[0m"
# define C_BOL "\e[1m"
# define C_GRN "\e[32m"
# define C_GRY "\e[90m"

# define TEST(X)	std::cout << C_GRN C_BOL << X << C_WHT << std::endl
# define POINT(X)	std::cout << C_GRY << X << C_WHT << std::endl

void runTests( void ) ;

#endif //----------------------------------------------------------------- TESTS.HPP