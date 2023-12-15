/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/12/04 08:19:37 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
Span::Span( void ) : _maxSize( 0 ), _v( 0 ) {}
Span::Span( uint N ) : _maxSize( N ), _v( 0 ) {}
Span::Span( Span const &rhs ) : _maxSize( rhs._maxSize ) { *this = rhs; }
Span::~Span( void ) {}


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
Span &Span::operator=( Span const &rhs ) {
	if ( this != &rhs ) {
		if ( this->_v.size() > 0 ) {
			this->_v.clear();
		}
		this->_v = rhs._v;
	}
	return *this;
}

ostream &operator<<( ostream &o, Span const &rhs ) {
	cout << C_BLU "VECTOR INFOS: " << endl;
	cout << C_BLU "  size: " C_WHT << rhs.getSize() << endl;
	cout << C_BLU "  size max: " C_WHT << rhs.getMaxSize() << endl;
	cout << C_BLU "  content: " C_WHT << endl;
	for ( int i = 0; i < rhs.getSize(); i++ ) {
		cout << "\t * vec[" << i << "]: " << rhs.getVector()[i] << endl;
	}
	return o;
}


/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */
int Span::getMaxSize() const { return this->_maxSize; };
int Span::getSize() const { return this->_v.size(); };
vector<int> Span::getVector() const { return this->_v; };


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
void Span::addNumber( int const toAdd ) {
	if ( (uint)this->_v.size() < this->_maxSize ) {
		this->_v.push_back( toAdd );
	} else {
		throw OverMaxSize();
	}
}

void Span::addNumber() {
	if ( (uint)this->_v.size() < this->_maxSize ) {
		vector<int> tmpVec( this->_maxSize );

		generate(tmpVec.begin(), tmpVec.end(), rand);
		this->_v.insert( this->_v.end(), tmpVec.begin(), tmpVec.end() );
	} else {
		throw OverMaxSize();
	}
}

int Span::longestSpan() const {
	int min, max = 0;
	if ( this->getSize() > 1 ) {
		max = *max_element( this->_v.begin(), this->_v.end() );
		min = *min_element( this->_v.begin(), this->_v.end() );
		cout << C_BLU "Shortest dist.: " C_WHT << "between " 
			<< min << " and " << max << endl;
		cout << "Distance = ";
		return max - min; 
	} else {
		throw SizeTooSmall();
	}
}

int Span::shortestSpan() const {
	if ( this->getSize() > 1 ) {
		vector<int> v_sort;

		v_sort = this->_v;
		sort( v_sort.begin(), v_sort.end() );

		int elem1, elem2 = 0;
		int shtDist = v_sort[1] - v_sort[0];
		for ( size_t i = 0; i < v_sort.size() - 1; i++ ) {
			if ( v_sort[i + 1] - v_sort[i] < shtDist ) {
				elem1 = v_sort[i];
				elem2 = v_sort[i + 1];
				shtDist = ( v_sort[i + 1] - v_sort[i] ) ;
			}
		}

		cout << C_BLU "Shortest dist.: " C_WHT << "between " 
			<< elem1 << " and " << elem2 << endl;
		cout << "Distance = ";
		return shtDist;
	} else {
		throw SizeTooSmall();
	}
}


/* ************************************************************************** */
/* Exceptions                                                                 */
/* ************************************************************************** */
const char *Span::OverMaxSize::what() const throw() {
	return C_BOL C_RED "Span::OverMaxSize" C_WHT; 
}

const char *Span::SizeTooSmall::what() const throw() {
	return C_BOL C_RED "Span::SizeTooSmall" C_WHT; 
}
