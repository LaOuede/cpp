/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dagger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/26 21:01:01 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DAGGER_HPP__
# define __DAGGER_HPP__

# include <iostream>
# include "AMateria.hpp"

using std::cout;
using std::endl;
using std::string;

class Dagger : public AMateria {
	public:
		// Construtors & Destructors
		Dagger( void ) ;                           //canonical
		Dagger( Dagger const & rhs );              //canonical
		~Dagger( void ) ;                          //canonical

		// Overload operators
		Dagger &operator=( Dagger const & rhs ) ;  //canonical

		// Methods
		virtual AMateria* clone( void ) const;
		void use( ICharacter& target ) ;
};

#endif//--------------------------------------------------------------DAGGER.HPP