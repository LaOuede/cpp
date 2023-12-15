/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/12/04 08:46:02 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
template <typename T>
MutantStack<T>::MutantStack( void ) {}

template <typename T>
MutantStack<T>::MutantStack( MutantStack const &rhs ) { *this = rhs; }

template <typename T>
MutantStack<T>::~MutantStack( void ) {}


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
template <typename T>
MutantStack<T> &MutantStack<T>::operator=( MutantStack const &rhs ) {
	stack<T>::operator=( rhs );
	return *this;
}


/* ************************************************************************** */
/* Iterators                                                                  */
/* ************************************************************************** */

/* c refers to the underlying container of the std::stack
from which MutantStack is derived.
c.begin() and c.end() return an iterator pointing to the beginning or the end 
of the underlying container */

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() { return this->c.begin(); }

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() { return this->c.end(); }