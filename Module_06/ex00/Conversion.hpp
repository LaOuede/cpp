/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/12/12 09:11:46 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONVERSION_HPP__
# define __CONVERSION_HPP__

# include <iomanip>
# include <iomanip>
# include <iostream>
# include <limits>
# include <string>

# define C_BOL "\e[1m"
# define C_BLU "\e[34m"
# define C_ITA "\e[3m"
# define C_RED "\e[31m"
# define C_WHT "\e[0m"

# define T_CHAR "char: "
# define T_INT "int: "
# define T_DOUBLE "double: "
# define T_FLOATB "float: "
# define T_FLOATE "f"
# define T_IMPOS "impossible"
# define T_NON_DISP "Non displayable"

using std::cerr;
using std::cout;
using std::count;
using std::endl;
using std::exception;
using std::fixed;
using std::numeric_limits;
using std::ostream;
using std::setprecision;
using std::string;

enum types {
	t_Empty,
	t_Char,
	t_Int,
	t_Double,
	t_Float,
	t_PseudoLit,
	t_Error
};

class Conversion {
	public:
		// Construtors & Destructors
		Conversion( void ) ;                               //canonical
		Conversion( string const toConvert ) ;
		Conversion( Conversion const & rhs );              //canonical
		~Conversion( void ) ;                              //canonical

		// Overload operators
		Conversion &operator=( Conversion const & rhs ) ;  //canonical

		// Getters and Setters
		string const &getString( void ) const ;
		int const &getPseudoLit( void ) const ;
		int const &getType( void ) const ;

		// Methods
		//// Step 1 : Find type
		bool findChar( void ) ;
		bool findDouble( void ) ;
		bool findFloat( void ) ;
		bool findInt( void ) ;
		bool findPseudoLit( void ) ;
		void findType( void ) ;
		bool utilsParsing( string type ) ;
		//// Step 2 : Print arg
		void printArg( void ) ;
		void printArgImpossibleToConvert() ;
		void printChar( void ) ;
		void printDouble( void ) ;
		void printFloat( void ) ;
		void printInt( void ) ;
		void printPseudoLit( void ) ;
		void utilsPrintPseudoLit( int F, int D ) ;
		//// Step 3: Explicitly convert arg to the other data types
		template <typename T>
		void convertToChar( T converted ) ;
		template <typename T>
		void convertToInt( T converted ) ;
		template <typename T>
		void convertToFloat( T converted ) ;
		template <typename T>
		void convertToDouble( T converted ) ;

		// Exceptions
		class ArgImpossibleToConvert : public exception {
			public:
				virtual const char* what() const throw() ;
		};

		class BadArgumentNumber : public exception {
			public:
				virtual const char* what() const throw() ;
		};

		class ImpossibleConversion : public exception {
			public:
				virtual const char* what() const throw() ;
		};

		class NonDisplayableConversion : public exception {
			public:
				virtual const char* what() const throw() ;
		};

	private:
		// Attributes
		string _toConvert;
		int _type;
		string _tab[6];
		int _pseudoLit;
};

// << Operator overload
ostream &operator<<( ostream &o, Conversion &rhs ) ;

#endif //-------------------------------------------------------- CONVERSION.HPP