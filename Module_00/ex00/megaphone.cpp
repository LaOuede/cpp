/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/06 15:13:04 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using std::cout;
using std::endl;

int main(int argc, char **argv) {

	if (argc == 1) {
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
		return 0 ;
	} else {
		for (int arg = 1; arg < argc; arg++) {
			std::string str = argv[arg];
			for (std::string::size_type i = 0; i < str.length(); i++) {
				cout << (char)std::toupper(str[i]);
			}
		}
	}
	cout << endl;
	return 0;
}