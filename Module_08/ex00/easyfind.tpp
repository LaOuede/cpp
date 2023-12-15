/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EasyFind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/12/01 12:15:58 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Exception
class EmptyContainer : public exception {
	public:
		virtual const char *what() const throw() {
			return C_BOL C_RED "Easyfind::EmptyContainer" C_WHT;
		}
};

class NotFound : public exception {
	public:
		virtual const char *what() const throw() {
			return C_BOL C_RED "Easyfind::ValueNotFound" C_WHT;
		}
};

// EasyFind function
template <typename T>
void easyfind( T const &numbers, int toFind ) {
	typename T::const_iterator it;

	if ( numbers.empty() ) {
		throw EmptyContainer();
		return ;
	}

	it = find( numbers.begin(), numbers.end(), toFind );

	if ( it == numbers.end() ) {
		throw NotFound();
		return ;
	}

	cout << C_ITA << toFind << " has been found!" << endl;
	return ;
}