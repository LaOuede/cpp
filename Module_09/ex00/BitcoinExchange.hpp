/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/12/13 09:52:11 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BTC_HPP__
# define __BTC_HPP__

# include <algorithm>
# include <fstream>
# include <iostream>
# include <map>
# include <regex>
# include <sstream>
# include <string>

# define C_BOL "\e[1m"
# define C_ITA "\e[3m"
# define C_GRN "\e[32m"
# define C_RED "\e[31m"
# define C_WHT "\e[0m"

# define ORIGIN 20090102
# define MAXDATE 20231231

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::ifstream;
using std::istringstream;
using std::map;
using std::pair;
using std::smatch;
using std::ostream;
using std::regex;
using std::string;

class BitcoinExchange {
	public:
		// Construtors & Destructors
		BitcoinExchange( string input_filename ) ;
		~BitcoinExchange( void ) ;                                  //canonical

		// Overload operators
		BitcoinExchange &operator=( BitcoinExchange const &rhs ) ;  //canonical

		// Methods
		void converter( void ) ;

		// Exceptions
		class DataFileError : public exception {
			public:
				virtual const char *what() const throw() ;
		};

		class UnableToOpenFile : public exception {
			public:
				virtual const char *what() const throw() ;
		};

	private:
		// Constructors & Destructors
		BitcoinExchange( void ) ;                                   //canonical
		BitcoinExchange( BitcoinExchange const &rhs );              //canonical
	
		// Methods
		/// STEP 1: data.csv parsing
		void dataBodyParsing( ifstream &csv_file ) ;
		void dataFileParsing( void ) ;
		void dataHeaderParsing( ifstream &csv_file ) ;
		/// STEP 2: map creation
		bool dataToMap( string line ) ;
		/// STEP 3: input parsing
		void inputBodyParsing( ifstream &file ) ;
		void inputFileParsing( string file ) ;
		void inputHeaderParsing( ifstream &file ) ;
		void inputLineParsing( string line, string value );
		/// STEP 4: Conversion
		float conversionRate( int date, float value ) ;
		// Utils
		bool dateParsing( string date, string line ) ;
		void isEmpty( ifstream &file, int flag ) ;
		int transformDate( string date ) ;

		// Attributes
		string _input;
		map<int, float> _data_map;
};

#endif //--------------------------------------------------------------- BTC.HPP