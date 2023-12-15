/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/12/14 08:12:12 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
template <typename Container, typename ContainerPair>
PmergeMe<Container, ContainerPair>::PmergeMe() {}

template <typename Container, typename ContainerPair>
PmergeMe<Container, ContainerPair>::PmergeMe( int argc, char **argv, string type, ContainerPair &pair ) :
	_argc( argc ),
	_input( argv ),
	_type( type ), 
	_pair( pair ) {}

template <typename Container, typename ContainerPair>
PmergeMe<Container, ContainerPair>::PmergeMe( PmergeMe const &rhs ) { *this = rhs; }

template <typename Container, typename ContainerPair>
PmergeMe<Container, ContainerPair>::~PmergeMe() {}


/* ************************************************************************** */
/* Overload operators                                                         */
/* ************************************************************************** */
template <typename Container, typename ContainerPair>
PmergeMe<Container, ContainerPair> &PmergeMe<Container, ContainerPair>::operator=( PmergeMe<Container, ContainerPair> const &rhs ) {
	(void) rhs;
	return *this;
}


/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */
// MAIN FUNCTION
template <typename Container, typename ContainerPair>
void PmergeMe<Container, ContainerPair>::sort( void ) {
	checkInput();
	parseInput();
	if ( DEBUG ) {
		fordJohnsonAlgo_Debug();
	} else {
		fordJohnsonAlgo();
	}
	checkSort();
}

// STEP 1 - INPUT PARSING
template <typename Container, typename ContainerPair>
void PmergeMe<Container, ContainerPair>::checkInput() const {
	if ( this->_argc < 3 ) {
		throw runtime_error("Error: arguments needed");
	}
}

template <typename Container, typename ContainerPair>
void PmergeMe<Container, ContainerPair>::parseInput() const {
	long nb1, nb2;

	for ( int i = 1; i < this->_argc; i++ ) {
		for (int j = i + 1; j < this->_argc; ++j) {
			nb1 = stol(this->_input[i]);
			nb2 = stol(this->_input[j]);
			if ( nb1 < 0 || nb2 < 0 ) {
				throw runtime_error( C_RED "Error: negative number" C_WHT );
			} else if ( nb1 > INT_MAX || nb2 > INT_MAX ) {
				throw runtime_error( C_RED "Error: INT overflow" C_WHT );
			} else if ( nb1 == nb2 ) {
				throw runtime_error( C_RED "Error: found duplicates" C_WHT );
				break;
			}
		}
	}
}


// STEP 2 - FORD JOHNSON ALGO
template <typename Container, typename ContainerPair>
void PmergeMe<Container, ContainerPair>::dataToContainer() {
	long nb_first, nb_second;

	for ( int i = 1; i < this->_argc; i += 2 ) {
		nb_first = stoi( this->_input[i] );
		if ( i == this->_argc - 1 ) {
			this->_pair.push_back( make_pair(nb_first, ERROR) );
			return ;
		}
		nb_second = stol( this->_input[i + 1] );
		if ( nb_first > nb_second ) {
			this->_pair.push_back( make_pair(nb_second, nb_first) );
		} else {
			this->_pair.push_back( make_pair(nb_first, nb_second) );
		}
	}
}

template <typename Container, typename ContainerPair>
void PmergeMe<Container, ContainerPair>::sortPairs() {
	bool swapped = true;
	PairIterator it;
	PairIterator it_;

	while ( swapped ) {
		swapped = false;
		for ( it = this->_pair.begin(); it != this->_pair.end(); it++ ) {
			it_ = it + 1;
			if ( it_ != this->_pair.end() && it->second > it_->second 
				&& it_->second != ERROR ) {
				iter_swap( it, it_ );
				swapped = true;
			}
		}
	}
}

template <typename Container, typename ContainerPair>
void PmergeMe<Container, ContainerPair>::chainsCreation() {
	PairIterator it;

	for ( it = this->_pair.begin(); it != this->_pair.end(); it++ ) {
		if ( it->second != ERROR ) {
			this->_main_chain.push_back( it->second );
		}
		this->_pend_chain.push_back( it->first );
	}
}

template <typename Container, typename ContainerPair>
void PmergeMe<Container, ContainerPair>::firstElementInsertion() {
		this->_main_chain.insert(this->_main_chain.begin(), this->_pend_chain.front());
}

template <typename Container, typename ContainerPair>
int PmergeMe<Container, ContainerPair>::jacobSthalNumber( int jsq_index ) {
	if (jsq_index == 0) {
		return 0;
	} else if (jsq_index == 1) {
		return 1;
	} else {
		return jacobSthalNumber( jsq_index - 1 ) + 2 * jacobSthalNumber( jsq_index - 2 );
	}
}

template <typename Container, typename ContainerPair>
void PmergeMe<Container, ContainerPair>::jacobSthalSequence() {
	int jsq_index = 3;

	this->_jsq.push_back( 1 );
	while ( jacobSthalNumber(jsq_index) < static_cast<int>(this->_pend_chain.size() - 1 )) {
		this->_jsq.push_back(jacobSthalNumber(jsq_index));
		jsq_index += 1;
	}
	this->_jsq.push_back( static_cast<int>(this->_pend_chain.size() ));
}

template <typename Container, typename ContainerPair>
void PmergeMe<Container, ContainerPair>::mergeInsertionSort() {
	int counter, index_target;
	ContainerIterator it;
	ContainerIterator jsq_current = this->_jsq.begin() + 1;
	ContainerIterator jsq_prev = this->_jsq.begin();

	while ( jsq_current != this->_jsq.end() ) {
		counter = 1;
		while ( *jsq_current > *jsq_prev ) {
			index_target = binarySearchTree( this->_pend_chain[*jsq_current - counter] );
			it = find( this->_main_chain.begin(), this->_main_chain.end(), index_target );
			if ( index_target == 0 ) {
				this->_main_chain.insert(this->_main_chain.begin(), this->_pend_chain[*jsq_current - counter] );
			} else {
				this->_main_chain.insert(it + 1, this->_pend_chain[*jsq_current - counter] );
			}
			*jsq_prev += 1;
			counter++;
		}
		jsq_current++;
		jsq_prev++;
	}
}

template <typename Container, typename ContainerPair>
int PmergeMe<Container, ContainerPair>::binarySearchTree( int const &nb ) {
	int start = 0;
	int middle = 0;
	int end = this->_main_chain.size();

	while (start < end) {
		middle = start + (end - start) / 2;
		if (this->_main_chain[middle] < nb) {
			start = middle + 1;
		} else {
			end = middle;
		}
	}
	if ( start == 0 ) {
		return 0;
	}
	return this->_main_chain[start - 1];
}

template <typename Container, typename ContainerPair>
void PmergeMe<Container, ContainerPair>::fordJohnsonAlgo() {
	timespec start, end;
	double execution_time;
	
	start = getTime();
	if ( this->_type == "vector" ) {
		printBefore();
	}
	dataToContainer();
	sortPairs();
	chainsCreation();
	firstElementInsertion() ;
	jacobSthalSequence();
	mergeInsertionSort();
	end = getTime();
	execution_time = time_difference( start, end );
	if ( this->_type == "vector" ) {
		printAfter( this->_main_chain );
	}
	printTime( execution_time );
}


// STEP 3 - VALIDATION
template <typename Container, typename ContainerPair>
void PmergeMe<Container, ContainerPair>::checkSort() {
	if ( is_sorted(this->_main_chain.begin(), this->_main_chain.end()) ) {
		cout << C_GRN C_ITA "is_sorted(input): true" C_WHT << endl;
		return ;
	}
	cout << C_RED C_ITA "is_sorted(input): false" C_WHT << endl;
}

template <typename Container, typename ContainerPair>
void PmergeMe<Container, ContainerPair>::printAfter( Container &chain ) const {
	typename Container::iterator it;

	cout << C_BOL C_BLU "After: " C_WHT << " [";
	for ( it = chain.begin(); it != chain.end(); it++ ) {
		cout << " " << *it;
	}
	cout << " ]" << endl;
}

template <typename Container, typename ContainerPair>
void PmergeMe<Container, ContainerPair>::printBefore() const {
	cout << C_BOL C_BLU "\nBefore:" C_WHT << " [";
	for ( int i = 1; i < this->_argc; i++ ) {
		cout << " " << this->_input[i];
	}
	cout << " ]" << endl;
}


// Utils
template <typename Container, typename ContainerPair>
timespec PmergeMe<Container, ContainerPair>::getTime() const {
	timespec current_time;

	clock_gettime(CLOCK_REALTIME, &current_time);
	return current_time;
}

template <typename Container, typename ContainerPair>
double PmergeMe<Container, ContainerPair>::time_difference(const timespec& start, const timespec& end) const {
	time_t sec, nano;
	double ms;

	sec = (end.tv_sec - start.tv_sec) * 1000000000;
	nano = end.tv_nsec - start.tv_nsec;
	ms = sec + nano;
	ms /= 1000000;
	return ms;
}

template <typename Container, typename ContainerPair>
void PmergeMe<Container, ContainerPair>::printChain( string const &name, Container &chain ) const {
	typename Container::iterator it;

	cout << name << " content: \n[" ;
	for ( it = chain.begin(); it != chain.end(); it++ ) {
		cout << " " << *it;
	}
	cout << " ]" << endl;
}

template <typename Container, typename ContainerPair>
void PmergeMe<Container, ContainerPair>::printTime( double execution_time ) const {
	cout << "Time to process a range of " << C_BOL C_BLU 
		<< this->_argc - 1 << C_WHT << " elements with std::" 
		<< C_BLU C_BOL << this->_type << ": " C_WHT << execution_time 
		<< " ms" << endl;
}

template <typename Container, typename ContainerPair>
void PmergeMe<Container, ContainerPair>::printPair() {
	PairIterator it;

	cout << "Vector_Pair content: " << endl;
	for ( it = this->_pair.begin(); it != this->_pair.end(); it++ ) {
		cout << "[ " << it->first << ", " << it->second << " ]" << endl;
	}
}

template <typename Container, typename ContainerPair>
void PmergeMe<Container, ContainerPair>::fordJohnsonAlgo_Debug() {
	timespec start, end;
	double execution_time;

	cout << C_BLU C_BOL "\n--- Input to sort ---" C_WHT << endl;
	printBefore();
	cout << C_BLU C_BOL "\n--- Make Pairs ---" C_WHT << endl;
	dataToContainer();
	printPair();
	cout << C_BLU C_BOL "\n--- Sort Pairs ---" C_WHT << endl;
	start = getTime();
	sortPairs();
	printPair();
	cout << C_BLU C_BOL "\n--- Chains creation ---" C_WHT << endl;
	chainsCreation();
	printChain( "Main chain", _main_chain );
	printChain( "Pend chain", _pend_chain );
	cout << C_BLU C_BOL "\n--- 1st element insertion ---" C_WHT << endl;
	firstElementInsertion() ;
	printChain( "Main chain", _main_chain );
	printChain( "Pend chain", _pend_chain );
	jacobSthalSequence();
	cout << C_BLU C_BOL "\n--- jsq chain ---" C_WHT << endl;
	printChain( "JSQ chain", _jsq );
	cout << C_BLU C_BOL "\n--- sort ---" C_WHT << endl;
	mergeInsertionSort();
	end = getTime();
	printChain( "Main chain", _main_chain );
	printChain( "Pend chain", _pend_chain );
	cout << C_BLU C_BOL "\n--- time ---" C_WHT << endl;
	execution_time = time_difference( start, end );
	printTime( execution_time );
}