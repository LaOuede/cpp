#include <iostream>
#include <string>
#include "student.class.hpp"

int main() {
	Student bob = Student("bfoobar");
	Student const jim = Student("jfoobar");

	std::cout << bob.getLoginRefConst() << " " << jim.getLoginRefConst() << std::endl;
	std::cout << *(bob.getLoginPtrConst()) << " " << *(jim.getLoginPtrConst()) << std::endl;

	bob.getLoginRef() = "bobfoobar";
	std::cout << bob.getLoginRefConst() << std::endl;

	*(bob.getLoginPtr()) = "bobbyfoobar";
	std::cout << bob.getLoginRefConst() << std::endl;

	return 0;
}