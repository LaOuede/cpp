/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/12/14 08:14:10 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PMERGEME_HPP__
# define __PMERGEME_HPP__

# include <algorithm>
# include <iostream>
# include <deque>
# include <string>
# include <sys/time.h>
# include <vector>

# define C_BLU "\e[34m"
# define C_BOL "\e[1m"
# define C_ITA "\e[3m"
# define C_GRN "\e[32m"
# define C_RED "\e[31m"
# define C_WHT "\e[0m"

# define ERROR -1

#ifndef DEBUG
# define DEBUG 0
#endif

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::deque;
using std::make_pair;
using std::ostream;
using std::pair;
using std::runtime_error;
using std::sort;
using std::stoi;
using std::stol;
using std::string;
using std::vector;

template <typename Container, typename ContainerPair>
class PmergeMe {
	public:
		// Construtors & Destructors
		PmergeMe( int argc, char **argv, string type, ContainerPair &pair ) ;
		~PmergeMe( void ) ;                           //canonical

		// Methods
		void sort( void ) ;

		// Typedef
		typedef typename Container::iterator ContainerIterator;
		typedef typename ContainerPair::iterator PairIterator;

	private:
		// Constructors
		PmergeMe( void ) ;                            //canonical
		PmergeMe( PmergeMe const &rhs );              //canonical

		// Methods
		/// STEP 1: input parsing
		void checkInput( void ) const ;
		void parseInput( void ) const ;
		/// STEP 2: sort
		int binarySearchTree( int const &nb ) ;
		void chainsCreation( void );
		void dataToContainer( void ) ;
		void firstElementInsertion( void ) ;
		void fordJohnsonAlgo( void ) ;
		int jacobSthalNumber( int jsq_index ) ;
		void jacobSthalSequence( void ) ;
		void mergeInsertionSort( void ) ;
		void sortPairs( void ) ;
		/// STEP 3: Validation
		void printAfter( Container &chain ) const ;
		void printBefore( void ) const ;
		void checkSort( void ) ;
		/// utils
		void fordJohnsonAlgo_Debug( void ) ;
		timespec getTime( void ) const ;
		void printChain( string const &name, Container &chain ) const ;
		void printTime( double execution_time ) const ;
		void printPair( void ) ;
		double time_difference(const timespec& start, const timespec& end) const ;

		// Attributes
		int _argc;
		char **_input;
		string _type;
		Container _jsq;
		Container _main_chain;
		Container _pend_chain;
		ContainerPair _pair;

		// Overload operators
		PmergeMe &operator=( PmergeMe const &rhs ) ;  //canonical
};

# include "PmergeMe.tpp"

#endif //---------------------------------------------------------- PMERGEME.HPP