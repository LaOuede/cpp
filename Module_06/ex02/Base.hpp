/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/29 12:49:30 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BASE_HPP__
# define __BASE_HPP__

# include <iostream>

# define C_BOL "\e[1m"
# define C_BLU "\e[34m"
# define C_GRN "\e[32m"
# define C_ITA "\e[3m"
# define C_WHT "\e[0m"

using std::cerr;
using std::cout;
using std::endl;
using std::bad_cast;
using std::exception;

class Base {
	public:
		// Destructor
		virtual ~Base( void ) ;
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif //-------------------------------------------------------------- BASE.HPP