/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/27 08:39:41 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifndef EVAL
# define EVAL 0
#endif

# define C_WHT "\e[0m"
# define C_BOL "\e[1m"
# define C_RED "\e[31m"
# define C_GRN "\e[32m"
# define C_BLU "\e[34m"

using std::cerr;
using std::cout;
using std::endl;
using std::string;

void displayMemory( string &str, string *strPtr, string &strRef ) {
	cout << "------------------ " << C_BOL << "Adresses" << C_WHT << " ------------------" << endl;
	cout << "Adresse de " << C_BOL << C_BLU << "brain" << C_WHT << " en mémoire   : " << &str << endl;
	cout << "Adresse stockée dans " << C_BOL << C_RED << "brainPtr" << C_WHT << " : " << strPtr << endl;
	cout << "Adresse stockée dans " << C_BOL << C_GRN << "brainRef" << C_WHT << " : " << &strRef << endl;
	cout << '\n';
}

void displayValue( string str, string *strPtr, string strRef ) {
	cout << "------------------- " << C_BOL << "Valeurs" << C_WHT << " ------------------" << endl;
	cout << "Valeur de " << C_BOL << C_BLU << "brain" << C_WHT << " en mémoire  : " << str << endl;
	cout << "Valeur pointée par " << C_BOL << C_RED << "brainPtr" << C_WHT << " : " << *strPtr << endl;
	cout << "Valeur pointée par " << C_BOL << C_GRN << "brainRef" << C_WHT << " : " << strRef << endl;
	cout << '\n';
}

int main( int argc, char **argv ) {

	(void) argv;
	if (argc > 1) {
		cerr << "Usage: Error : bad arguments" << endl;
		return 1;
	}

	// Declaration
	string brain = "HI THIS IS BRAIN";
	string* brainPtr = &brain;
	string& brainRef = brain;

	// Display Memory
	displayMemory(brain, brainPtr, brainRef);
	// Display Value
	displayValue(brain, brainPtr, brainRef);


	/* ***************************************************************************************** */
	/*                                           TESTS                                           */
	/* ***************************************************************************************** */
	if (EVAL) {
		cout << C_BOL << "******** TEST 1 : Change the value of brain **********" << C_WHT << endl;
		// Declaration
		brain = "I NEED MORE BRAIIINNNNZ";
		// Display Memory
		displayMemory(brain, brainPtr, brainRef);
		// Display Value
		displayValue(brain, brainPtr, brainRef);


		cout << C_BOL << "\n*** TEST 2 : Change the value pointed by brainPtr ****" << C_WHT << endl;
		// Declaration
		*brainPtr = "BRAIN WAS HERE";
		// Display Memory
		displayMemory(brain, brainPtr, brainRef);
		// Display Value
		displayValue(brain, brainPtr, brainRef);


		cout << C_BOL << "\n*** TEST 3 : Change the value pointed by brainRef ****" << C_WHT << endl;
		// Declaration
		brainRef = "I'M A UNICORN";
		// Display Memory
		displayMemory(brain, brainPtr, brainRef);
		// Display Value
		displayValue(brain, brainPtr, brainRef);
	}

	return 0;
}