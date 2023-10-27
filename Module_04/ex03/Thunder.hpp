/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Thunder.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/26 21:01:56 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __THUNDER_HPP__
# define __THUNDER_HPP__

# include <iostream>
# include "AMateria.hpp"

using std::cout;
using std::endl;
using std::string;

class Thunder : public AMateria {
	public:
		// Construtors & Destructors
		Thunder( void ) ;                            //canonical
		Thunder( Thunder const & rhs );              //canonical
		~Thunder( void ) ;                           //canonical

		// Overload operators
		Thunder &operator=( Thunder const & rhs ) ;  //canonical

		// Methods
		virtual AMateria* clone( void ) const;
		void use( ICharacter& target ) ;
};

#endif//-------------------------------------------------------------THUNDER.HPP