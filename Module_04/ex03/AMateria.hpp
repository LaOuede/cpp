/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/24 14:42:23 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AMATERIA_HPP__
# define __AMATERIA_HPP__

# include <iostream>
# include "ICharacter.hpp"

using std::cout;
using std::endl;
using std::string;

class AMateria {
	protected:
		// Attributes
		string _type;
	
	public:
		// Construtors & Destructors
		AMateria( void ) ;                             //canonical
		AMateria( string const & type );
		AMateria( AMateria const & rhs );              //canonical
		virtual ~AMateria( void ) ;                    //canonical

		// Overload operators
		AMateria &operator=( AMateria const & rhs ) ;  //canonical

		// Getters and Setters
		string const & getType( void ) const ;

		// Methods
		virtual AMateria* clone( void ) const = 0;
		virtual void use( ICharacter& target ) ;
};

#endif//------------------------------------------------------------AMATERIA.HPP