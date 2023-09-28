#include <iostream>
#include <fstream>

int main() {

	std::ifstream ifs("numbers"); // ifstream = input file stream
	unsigned int dst;
	unsigned int dst2;
	ifs >> dst >> dst2;

	std::cout << dst << " " << dst2 << std::endl;
	ifs.close();

	//---------------------------------------------

	std::ofstream ofs("test.out"); // ofstream = output file stream

	ofs << "i like ponies a whole damn lot" << std::endl;
	ofs.close();
}
