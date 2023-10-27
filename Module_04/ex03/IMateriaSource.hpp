/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/26 20:55:04 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __IMATERIASOURCE_HPP__
# define __IMATERIASOURCE_HPP__

# include <iostream>
# include "AMateria.hpp"

using std::string;

class IMateriaSource {
	public:
		// Construtors & Destructors
		virtual ~IMateriaSource( void ) {}

		// Methods
		virtual void learnMateria( AMateria* ) = 0;
		virtual AMateria* createMateria( string const & type ) = 0;
};

#endif//------------------------------------------------------IMATERIASOURCE.HPP