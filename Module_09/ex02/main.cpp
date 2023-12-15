/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/12/14 08:15:13 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	try {
		string type = "vector";
		vector<pair<int, int> > vec_pair;
		PmergeMe<vector<int>, vector<pair<int, int> > > v( argc, argv, type, vec_pair );
		v.sort();

		type = "deque";
		deque<pair<int, int> > deque_pair;
		PmergeMe<deque<int>, deque<pair<int, int> > > l( argc, argv, type, deque_pair );
		l.sort();
	} catch ( exception &e ) {
		cerr << e.what() << endl;
	}
	return 0;
}