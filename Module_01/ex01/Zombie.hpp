/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/27 08:39:27 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_HPP__
# define __ZOMBIE_HPP__

#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class Zombie {
	public:
		// Constructor & Destructor
		Zombie( void ) ;
		~Zombie( void ) ;

		// Setter
		void setName( string name ) ;

		// Methods
		void annouce( void ) ;

	private:
		// Attributes
		std::string _m_name;
};

#endif