/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/30 14:03:55 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
template <typename T>
Array<T>::Array() : _array( new T[0] ), _size( 0 ) {
	cout << C_ITA << "Array - Default constructor called" C_WHT << endl;
}

template <typename T>
Array<T>::Array( unsigned int n ) : _array( new T[n] ), _size( n ) {
	cout << C_ITA << "Array - Parametric constructor called" C_WHT << endl;
}

template <typename T>
Array<T>::Array( Array const &rhs ) : _array( new T[0] ) {
	cout << C_ITA << "Array - Copy constructor called" C_WHT << endl;
	*this = rhs;
}

template <typename T>
Array<T>::~Array( void ) {
	cout << C_ITA << "Array - Default destructor called" C_WHT << endl;
	delete [] this->_array;
}


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
template <typename T>
Array<T> &Array<T>::operator=( Array const &rhs ) {
	cout << C_ITA << "Array - Assignment constructor called" C_WHT << endl;
	if ( this != &rhs ) {
		delete [] this->_array;
		this->_size = rhs._size;
		this->_array = new T[rhs.size()];

		for ( unsigned int i = 0; i < this->_size; i++ ) {
			this->_array[i] = rhs._array[i];
		}
	}

	return *this;
}

template <typename T>
T &Array<T>::operator[]( unsigned int index ) {
	if ( index < 0 || index >= this->_size ) {
		throw BadIndex();
	}
	return this->_array[index];
}


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
template <typename T>
unsigned int Array<T>::size() const { return _size; }


/* ************************************************************************** */
/* Exceptions                                                                 */
/* ************************************************************************** */
template <typename T>
const char *Array<T>::BadIndex::what() const throw() {
	return C_BOL C_RED "Array::BadIndex" C_WHT;
}