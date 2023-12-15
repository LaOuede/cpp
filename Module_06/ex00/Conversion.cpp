/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/30 08:07:51 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"
#include "Tests.hpp"

/*
The notion of transforming the encoding of a byte to another encoding in order 
to keep the same value is called a conversion.
*/


/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
Conversion::Conversion() :
	_toConvert( "Default" ), _type( t_Empty ) {
	_tab[0] = "+inf";
	_tab[1] = "-inf";
	_tab[2] = "+inff";
	_tab[3] = "-inff";
	_tab[4] = "nan";
	_tab[5] = "nanf";
	}

Conversion::Conversion( string const toConvert ) :
	_toConvert( toConvert ), _type( t_Empty ) {
	_tab[0] = "+inf";
	_tab[1] = "-inf";
	_tab[2] = "+inff";
	_tab[3] = "-inff";
	_tab[4] = "nan";
	_tab[5] = "nanf";
	}

Conversion::Conversion( Conversion const & rhs ) {
	*this = rhs;
}

Conversion::~Conversion() {}


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
Conversion &Conversion::operator=( Conversion const &rhs ) {
	if ( this != &rhs) {
		this->_toConvert = rhs.getString();
		this->_type = rhs.getType();
		this->_pseudoLit = rhs.getPseudoLit();
	}
	return *this;
}

ostream &operator<<( ostream &o, Conversion &rhs ) {
	rhs.findType();
	if ( DEBUG ) {
		cout << C_BLU "_toConvert: " C_WHT << rhs.getString() << endl;
		cout << C_BLU "_type: " C_WHT << rhs.getType() << endl;
	}
	rhs.printArg();
	return o;
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */
string const &Conversion::getString() const { return this->_toConvert; }
int const &Conversion::getPseudoLit() const { return this->_pseudoLit; }
int const &Conversion::getType() const { return this->_type; }


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
//// Step 1 : Find type
bool Conversion::findChar() {
	if ( this->_toConvert.length() > 1 || isdigit( this->_toConvert[0]) ) {
		return false;
	}
	this->_type = t_Char;
	return true;
}

bool Conversion::findDouble() {
	if ( this->_type != t_Empty ) {
		return false;
	}
	try {
		stod( this->_toConvert );
		size_t found = this->_toConvert.find_first_not_of("+-0123456789.");
		if ( found != string::npos || this->_toConvert.back() == '.' ) {
		return false;
		}
		if ( !utilsParsing( "Double" ) ) {
			return false;
		}
		this->_type = t_Double;
		return true;
	} catch ( exception &e ) {
		return false;
	}
}

bool Conversion::findFloat() {
	if ( this->_type != t_Empty ) {
		return false;
	}
	try {
		stof( this->_toConvert );
		size_t found = this->_toConvert.find_first_not_of("+-0123456789.f");
		if ( found != string::npos || this->_toConvert.back() != 'f' ) {
			return false;
		}
		if ( !utilsParsing( "Float" ) ) {
			return false;
		}
		this->_type = t_Float;
		return true;
	} catch ( exception &e ) {
		return false;
	}
}

bool Conversion::findInt() {
	if ( this->_type != t_Empty || this->_toConvert.length() > 11 ) {
		return false;
	} 
	try {
		stoi( this->_toConvert ) ;
		size_t found = this->_toConvert.find_first_not_of("+-0123456789");
		if ( found != string::npos ) {
			return false;
		}
		if ( !utilsParsing( "Int" ) ) {
			return false;
		}
		this->_type = t_Int;
		return true;
	} catch ( exception &e ) {
		return false;
	}
}

bool Conversion::findPseudoLit() {
	if ( this->_type != t_Empty ) {
		return false;
	}
	for ( int i = 0; i < 6; i++ ) {
		if ( this->_toConvert == _tab[i] ) {
			this->_pseudoLit = i;
			this->_type = t_PseudoLit;
			return true;
		}
	}
	return false;
}

void Conversion::findType() {
	if ( findChar() ) {
		this->_type = t_Char;
	} else if ( findInt() ) {
		this->_type = t_Int;
	} else if ( findDouble() ) {
		this->_type = t_Double;
	} else if ( findFloat() ) {
		this->_type = t_Float;
	} else if ( findPseudoLit() ) {
		this->_type = t_PseudoLit;
	} else if ( this->_type == t_Empty ) {
		this->_type = t_Error;
	}
}

bool Conversion::utilsParsing( string type ) {
	if ( type == "Float" ) {
		int count_end = 0;
		int count_f = 0;
		for ( int i = 0; i < (int)this->_toConvert.size(); i++ ) {
			if ( this->_toConvert[i] == '.') {
				count_end++;
			}
			if ( this->_toConvert[i] == 'f') {
				count_f++;
			}
		}
		if ( count_end > 1 || count_f > 1 ) {
			return false;
		}
	}
	for ( int i = 0; i < (int)this->_toConvert.size(); i++ ) {
		if ( (this->_toConvert[i] == '+' || this->_toConvert[i] == '-') && i != 0 ) {
			return false;
		}
	}
	return true;
}


//// Step 2 : Print arg
void Conversion::printArg() {
	switch (this->_type) {
	case t_Char:
		printChar();
		break;
	case t_Int:
		printInt();
		break;
	case t_Double:
		printDouble();
		break;
	case t_Float:
		printFloat();
		break;
	case t_PseudoLit:
		printPseudoLit();
		break;
	default:
		printArgImpossibleToConvert();
		throw ArgImpossibleToConvert();
	}
}

void Conversion::printArgImpossibleToConvert() {
	cout << T_CHAR << T_IMPOS << endl;
	cout << T_INT << T_IMPOS << endl;
	cout << T_FLOATB << T_IMPOS << endl;
	cout << T_DOUBLE << T_IMPOS << endl;
}

void Conversion::printChar() {
	char converted = this->_toConvert[0];

	cout << T_CHAR << "'" << converted << "'" << endl;
	convertToInt(converted);
	convertToFloat(converted);
	convertToDouble(converted);
}

void Conversion::printDouble() {
	double converted = stod( this->_toConvert );

	convertToChar(converted);
	convertToInt(converted);
	convertToFloat(converted);
	cout << T_DOUBLE << fixed << setprecision(1) << converted << endl;
}

void Conversion::printFloat() {
	float converted = stof( this->_toConvert );

	convertToChar(converted);
	convertToInt(converted);
	cout << T_FLOATB << fixed << setprecision(1) << converted << T_FLOATE << endl;
	convertToDouble(converted);
}

void Conversion::printInt() {
	int converted = stoi( this->_toConvert );

	convertToChar(converted);
	cout << T_INT << this->_toConvert << endl;
	convertToFloat(converted);
	convertToDouble(converted);
}

void Conversion::printPseudoLit() {
	if ( this->_pseudoLit == 0 || this->_pseudoLit == 2 ) {
		utilsPrintPseudoLit( 0, 2 );
	} else if ( this->_pseudoLit == 1 || this->_pseudoLit == 3 ) {
		utilsPrintPseudoLit( 1, 3 );
	} else {
		utilsPrintPseudoLit( 4, 5 );
	}
}

void Conversion::utilsPrintPseudoLit( int D, int F) {
	cout << T_CHAR << T_IMPOS << endl;
	cout << T_INT << T_IMPOS << endl;
	cout << T_FLOATB << this->_tab[F] << endl;
	cout << T_DOUBLE << this->_tab[D] << endl;
}

//// Step 3: Explicitly convert arg to the other data types
/*
Static_cast :
We use static_cast as we need to convert, Upcast and Downcast.
As we need to Downcast, we can't make an implicit conversion.
*/
template <typename T>
void Conversion::convertToChar( T converted ) {
	try {
		if ( converted < CHAR_MIN || converted > CHAR_MAX ) {
			throw( ImpossibleConversion() );
		} else if ( isprint(converted) ) {
			cout << T_CHAR << "'" << static_cast<char>(converted) << "'" << endl;
		} else {
			throw( NonDisplayableConversion() );
		}
	} catch ( exception &e ) {
		cerr << T_CHAR << e.what() << endl;
	}
}

template <typename T>
void Conversion::convertToInt( T converted ) {
	try {
		if ( converted < INT_MIN || converted > INT_MAX) {
			throw( ImpossibleConversion() );
		} else {
			cout << T_INT << static_cast<int>(converted) << endl;
		}
	} catch ( exception &e ) {
		cerr << T_INT << e.what() << endl;
	}
}

template <typename T>
void Conversion::convertToFloat( T converted ) {
	try {
		if ( converted > numeric_limits<T>::max() 
			|| converted < numeric_limits<T>::min() ) {
				throw ( ImpossibleConversion() );
		} else {
			cout << T_FLOATB << fixed << setprecision(1)
				<< static_cast<float>(converted) << T_FLOATE << endl;
		}
	} catch ( exception &e ) {
			cerr << T_FLOATB << e.what() << endl;
	}
}

template <typename T>
void Conversion::convertToDouble( T converted ) {
	cout << T_DOUBLE << fixed << setprecision(1)
		<< static_cast<double>(converted) << endl;
}


/* ************************************************************************** */
/* Exceptions                                                                 */
/* ************************************************************************** */
const char* Conversion::ArgImpossibleToConvert::what() const throw() {
	return C_BOL C_RED "./Conversion: Argument impossible to convert" C_WHT;
}

const char* Conversion::BadArgumentNumber::what() const throw() {
	return C_BOL C_RED "./Conversion [ One argument needed ]" C_WHT;
}

const char* Conversion::ImpossibleConversion::what() const throw() {
	return "impossible";
}

const char* Conversion::NonDisplayableConversion::what() const throw() {
	return "non displayable";
}