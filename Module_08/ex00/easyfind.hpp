/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EasyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/12/01 12:15:20 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EASYFIND_HPP__
# define __EASYFIND_HPP__

# include <algorithm>
# include <iostream>

# define C_BOL "\e[1m"
# define C_ITA "\e[3m"
# define C_RED "\e[31m"
# define C_WHT "\e[0m"

using std::cout;
using std::endl;
using std::exception;
using std::find;

// EasyFind function
template <typename T>
void easyfind( T const &numbers, int toFind ) ;

# include "easyfind.tpp"

#endif //---------------------------------------------------------- EASYFIND.HPP