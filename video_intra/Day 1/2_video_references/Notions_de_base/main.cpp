#include <iostream>

int main() {
	int numberOfBalls = 42;

	int *ballsPtr = &numberOfBalls;
	int &ballsRef = numberOfBalls;

	std::cout << "Number of Balls : " << numberOfBalls << std::endl;
	std::cout << "*ballsPtr : " << *ballsPtr << std::endl;
	std::cout << "ballsReff : " << ballsRef << std::endl;

	*ballsPtr = 21;
	std::cout << "Number of balls : " << numberOfBalls << std::endl;
	ballsRef = 84;
	std::cout << "Number of balls : " << numberOfBalls << std::endl;

	return 0;
}