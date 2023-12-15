/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/12/13 09:58:41 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange( string input_fileName ): _input( input_fileName ) {}
BitcoinExchange::BitcoinExchange( BitcoinExchange const &rhs ) { *this = rhs; }
BitcoinExchange::~BitcoinExchange() {}


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
BitcoinExchange &BitcoinExchange::operator=( BitcoinExchange const &rhs ) {
	if ( this != &rhs ) {
		this->_input = rhs._input;
		this->_data_map = rhs._data_map;
	}
	return *this;
}


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
// STEP 1 - DATA.CSV PARSING
void BitcoinExchange::isEmpty( ifstream &file, int flag ) {
	if ( flag == 0 ) {
		cerr << "The file is empty." << endl;
		file.close();
		throw DataFileError();
	}
}

void BitcoinExchange::dataBodyParsing( ifstream &csv_file ) {
	int flag = 0;
	string line;
	smatch match;
	regex pattern( "^(\\d{4}-\\d{2}-\\d{2}),(\\d*(\\.\\d+)?\\d*)$" );

	while ( getline(csv_file, line) ) {
		flag++;
		if ( !regex_search(line, match, pattern) ) {
			cout << C_ITA "Problem at this line: " C_WHT << line << endl;
			csv_file.close();
			throw DataFileError();
		}
		if ( !dataToMap(line) ) {
			csv_file.close();
			throw DataFileError();
		}
	}
	isEmpty( csv_file, flag );
}

void BitcoinExchange::dataHeaderParsing( ifstream &csv_file ) {
	string header_line;

	getline( csv_file, header_line );
	if ( header_line.empty() ) {
		cout << C_ITA "File is empty" << endl;
		csv_file.close();
		throw DataFileError();
	} else if ( header_line != "date,exchange_rate" ) {
		cout << C_ITA "Problem in header line: " C_WHT << header_line << endl;
		csv_file.close();
		throw DataFileError();
	}
}

void BitcoinExchange::dataFileParsing() {
	ifstream csv_file("data.csv");

	if ( csv_file.is_open() ) {
		dataHeaderParsing( csv_file );
		dataBodyParsing( csv_file );
		csv_file.close();
		return ;
	}
	throw UnableToOpenFile();
}


// STEP 2 - MAP CREATION
bool BitcoinExchange::dataToMap( string line ) {
	istringstream iss( line );
	string before, date, exchange_rate;

	before = line;
	getline(iss, date, ',');
	getline( iss, exchange_rate );
	if ( dateParsing(date, before) ) {
		this->_data_map.insert(pair<int, float>(transformDate( date ), stof(exchange_rate)));
		return true;
	}
	return false;
}


// STEP 3 - INPUT PARSING
void BitcoinExchange::inputLineParsing( string date, string value ) {
	int t_date = transformDate( date );
	float f_value = stof(value);

	if ( t_date < ORIGIN || t_date > MAXDATE ) {
		cout << "Error: date out of boundaries." << endl;
	} else if ( f_value < 0 ) {
		cout << "Error: not a positive number." << endl;
	} else if ( f_value > 1000 ) {
		cout << "Error: too large a number." << endl;
	} else {
		cout << date << " => " << f_value << " = " 
			<< conversionRate( t_date, f_value ) << endl;
	}
}

void BitcoinExchange::inputBodyParsing( ifstream &file ) {
	int flag = 0;
	string line;
	regex pattern( "^(\\d{4}-\\d{2}-\\d{2}) \\| (\\-*\\d+(\\.\\d+)?\\d*)$" );
	
	while ( getline( file, line )) {
		flag++;
		smatch match;
		if ( regex_search( line, match, pattern )) {
			string before = line;
			line.erase( remove(line.begin(), line.end(), ' '), line.end() );
			istringstream iss( line );
			string date, value;

			getline(iss, date, '|');
			getline( iss, value );
			if ( dateParsing(date, before) ) {
				inputLineParsing( date, value );
			}
		} else {
			cout << "Error: bad input => " << line << endl;
		}
	}
	isEmpty( file, flag );
}

void BitcoinExchange::inputHeaderParsing( ifstream &file ) {
	string header_line;

	getline( file, header_line );
	if ( header_line.empty() ) {
		cout << C_ITA "File is empty" << endl;
		file.close();
		throw DataFileError();
	} else if ( header_line != "date | value" ) {
		cout << C_ITA "Problem in header line: " C_WHT << header_line << endl;
		file.close();
		throw DataFileError();
	}
}

void BitcoinExchange::inputFileParsing( string filename) {
	ifstream input_file( filename );

	if ( input_file.is_open() ) {
		inputHeaderParsing( input_file );
		inputBodyParsing( input_file );
		input_file.close();
		return ;
	}
	throw UnableToOpenFile();
}


// STEP 4 - CONVERSION
float BitcoinExchange::conversionRate( int date, float value ) {
	float res = 0.0f;
	map<int, float>::iterator it;

	for ( it = this->_data_map.begin(); it != this->_data_map.end(); ++it ) {
		if ( date >= it->first ) {
			res = it->second * value;
		}
	}
	return res;
}


// UTILS
void BitcoinExchange::converter() {
	this->dataFileParsing();
	this->inputFileParsing( this->_input );
}

bool BitcoinExchange::dateParsing( string date, string line ) {
	char dash;
	int year, month, day;
	istringstream p_date( date );

	p_date >> year >> dash >> month >> dash >> day;
	if ( (month < 1 || month > 12) || (day < 1 || day > 31) 
		|| (month == 2 && day > 29) || (month == 4 && day > 30) 
		|| (month == 6 && day > 30) || (month == 9 && day > 30) 
		|| (month == 11 && day > 30)) {
		cout << "Error: bad input => " << line << endl;
		return false;
	}
	if ( month == 2 && day > 28 && 
		(!(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ) {
		cout << "Error: bad input => " << line << endl;
		return false;
	}
	return true;
}

int BitcoinExchange::transformDate( string date ) {
	char dash;
	istringstream t_date( date );
	int dateInt, year, month, day;
	
	t_date >> year >> dash >> month >> dash >> day;
	dateInt = year * 10000 + month * 100 + day;
	return dateInt;
}


/* ************************************************************************** */
/* Exceptions                                                                 */
/* ************************************************************************** */
const char *BitcoinExchange::DataFileError::what() const throw() {
	return C_BOL C_RED "BitcoinExchange::DataFileError" C_WHT;
}

const char *BitcoinExchange::UnableToOpenFile::what() const throw() {
	return "Error: could not open file.";
}


/* ************************************************************************** */
/* Comments                                                                   */
/* ************************************************************************** */
/* REGEX
Regex pattern explanation:
	ex: regex pattern( "^(\\d{4}-\\d{2}-\\d{2}),(\\d*(\\.\\d+)?\\d*)$" );

	^: asserts the start of the line
	(\\d{4}-\\d{2}-\\d{2}) : matches the date in the format YYYY-MM-DD
	,: matches the comma that separates the date and the numeric value
	(\\d*(\\.\\d*)?\\d*): matches the numeric value
	*: zero or more occurence
	+: one or more occurence
	?: optional
	$: asserts the end of the line
*/