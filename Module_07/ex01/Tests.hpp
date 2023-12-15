/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/30 12:07:40 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TESTS_HPP__
# define __TESTS_HPP__

# include <cstdlib>
# include <iostream>

# include "Iter.hpp"

using std::cout;
using std::endl;
using std::string;
using std::ostream;

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

// Class Test
class Test {
	public:
		Test( string order, uint mana, string favWeapon ) ;
		~Test( void );
		string const &getOrder( void ) const ;
		uint const &getMana( void ) const ;
			string const &getfavWeapon( void ) const ;

	private:
		string _order;
		uint _mana;
		string _favWeapon;
};

ostream &operator<<( ostream &o, Test const &rhs );

#endif //------------------------------------------------------------- TESTS.HPP