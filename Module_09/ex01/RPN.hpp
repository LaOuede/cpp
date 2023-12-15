/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/12/13 10:12:53 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RPN_HPP__
# define __RPN_HPP__

# include <algorithm>
# include <iostream>
# include <stack>
# include <stdexcept>
# include <string>

# define C_BOL "\e[1m"
# define C_ITA "\e[3m"
# define C_GRN "\e[32m"
# define C_RED "\e[31m"
# define C_WHT "\e[0m"

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::stack;
using std::ostream;
using std::runtime_error;
using std::string;

class RPN {
	public:
		// Construtors & Destructors
		RPN( string input ) ;
		~RPN( void ) ;                      //canonical

		// Methods
		void calculator( void ) ;

	private:
		struct _operands {
			int operand1;
			int operand2;
		};

		// Constructors
		RPN( void ) ;                       //canonical
		RPN( RPN const &rhs );              //canonical

		// Overload operators
		RPN &operator=( RPN const &rhs ) ;  //canonical

		// Methods
		/// STEP 1: input parsing
		void checkInput( void ) ;
		void checkString( void ) ;
		void checkTokenThrowCalcul( void );
		bool isOperator( char const &c ) ;
		/// STEP 2: Calcul
		void doOperation( _operands &nbs ) ;
		_operands extractOperands( void ) ;
		void tryOperation( void );
		/// STEP 3: Validation
		void checkRest( void ) ;

		// Attributes
		int _operator;
		string _input;
		stack<int> _data_stack;

		enum _operators {
			PLUS = 1,
			MIN = 2,
			MULT = 3,
			DIV = 4,
		};
};

#endif //--------------------------------------------------------------- RPN.HPP