/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/25 18:05:09 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MATERIASOURCE_HPP__
# define __MATERIASOURCE_HPP__

# include <iostream>
# include "IMateriaSource.hpp"

# define MATERIA_SIZE 4

using std::cout;
using std::endl;
using std::string;

class MateriaSource : public IMateriaSource {
	public:
		// Construtors & Destructors
		MateriaSource( void ) ;                                  //canonical
		MateriaSource( MateriaSource const & rhs );              //canonical
		~MateriaSource( void ) ;                                 //canonical

		// Overload operators
		MateriaSource &operator=( MateriaSource const & rhs ) ;  //canonical

		// Getters and Setters
		AMateria * getMateria( uint idx ) const ;

		// Methods
		void learnMateria( AMateria* ) ;
		virtual AMateria* createMateria( string const & type ) ;

	private:
		// Attributes
		AMateria* _materia[MATERIA_SIZE];
		uint _nbMateria;

};

#endif//-------------------------------------------------------MATERIASOURCE.HPP