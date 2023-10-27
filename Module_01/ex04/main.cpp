/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/11 17:27:18 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::size_t;
using std::string;

int replaceWord(char **argv) {
	// ifstream = input file stream
	ifstream ifs(argv[1]);
	string infileName = argv[1];

	if (!ifs.is_open()) {
		cerr << "Usage: Error: " << infileName << " can't be opened" << endl;
		return 1;
	}

	// ofstream = output file stream
	string outfileName = infileName + ".replace";
	ofstream ofs(outfileName);

	if (!ofs.is_open()) {
		cerr << "Usage: Error: " << outfileName << " can't be opened" << endl;
		ifs.close();
		return 1;
	}

	// String to find and str to insert
	string toFind = argv[2];
	string toInsert = argv[3];

	if (!toFind.compare(toInsert)) {
		cerr << "Usage: Error: strToFind and strToInsert are the same" << endl;
		return 1;
	}

	// Getline, erase, insert and write in outfile
	string line;
	size_t found;
	int count = 1;
	int nbLine = 1;

	do {
		getline(ifs, line);
		while ((found = line.find(toFind))!= string::npos) {
			cout << "Occurence #" << count << " of \"" << toFind
				<< "\" found at line : " << nbLine << " (char : "
				<< found << ")" << endl;
			line.erase(found, toFind.length()).insert(found, toInsert);
			count++;
		}
		nbLine++;
		if (ifs.eof())
			ofs << line;
		else
			ofs << line << endl;
	} while (!ifs.eof());

	ifs.close();
	ofs.close();
	return 0;
}

int main ( int argc, char **argv ) {
	if (argc != 4) {
		cerr << "Usage: Error: bad arguments" << endl;
		cerr << "Usage: <filename> <strToFind> <strToInsert>" << endl;
		return 1 ;
	}
	return (replaceWord(argv));
}