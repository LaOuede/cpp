#include <iostream>
#include "Sample.class.hpp"

int main() {
	Sample instance;

	instance.m_publicFoo = 42;
	std::cout << "instance.publicFoo: " << instance.m_publicFoo << std::endl;
	//instance._privateFoo = 17;
	//std::cout << "instance._privateFoo: " << instance._privateFoo << std::endl;

	instance.publicBar();
	//instance _privateBar(); Ne fonctionne pas car private
	return 0;
}