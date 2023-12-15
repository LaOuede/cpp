/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/11/29 08:16:13 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DATA_HPP__
# define __DATA_HPP__

# include <iostream>
# include <string>

# define C_BOL "\e[1m"
# define C_BLU "\e[34m"
# define C_ITA "\e[3m"
# define C_WHT "\e[0m"

using std::cerr;
using std::cout;
using std::endl;
using std::string;

struct Data {
	string str;
	int nb;
	char c;
	float f;
};

uintptr_t serialize( Data *ptr ) ;
Data *deserialize( uintptr_t raw ) ;
void printData( Data *x, string dataName ) ;

#endif //-------------------------------------------------------------- DATA.HPP