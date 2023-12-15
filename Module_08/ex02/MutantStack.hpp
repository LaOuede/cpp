/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/12/04 08:46:07 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANTSTACK_HPP__
# define __MUTANTSTACK_HPP__

# include <algorithm>
# include <iostream>
# include <stack>

# define C_BOL "\e[1m"
# define C_BLU "\e[34m"
# define C_ITA "\e[3m"
# define C_RED "\e[31m"
# define C_WHT "\e[0m"

using std::cout;
using std::endl;
using std::stack;

template <typename T >
class MutantStack : public stack<T> {
	public:
		// Const. & Dest.
		MutantStack( void ) ;                               //canonical
		MutantStack( MutantStack const &rhs ) ;             //canonical
		~MutantStack( void ) ;                              //canonical

		// Operators overload
		MutantStack &operator=( MutantStack const &rhs ) ;  //canonical

		// Defines a type alias named iterator representing the iterator type
		// of the underlying container used by std::stack<T>
		typedef typename stack<T>::container_type::iterator iterator;

		// Iterators
		iterator begin( void ) ;
		iterator end( void ) ;
};

# include "MutantStack.tpp"

#endif //------------------------------------------------------- MUTANTSTACK.HPP