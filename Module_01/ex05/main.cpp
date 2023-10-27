/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/11 15:51:01 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main ( int argc, char **argv ){
	Harl harl;
	if (argc == 2)
		harl.complain(argv[1]);
	else {
		cerr << "Dont'forget about arguments! Don't be crazy!" << endl;
		cerr << "Crazy? I Was Crazy Once. They Locked Me In A Room. A Rubber Room."
			<< " A Rubber Room With Rats. And Rats Make Me Crazy." << endl;
		return 1;
	}
	return 0;
}