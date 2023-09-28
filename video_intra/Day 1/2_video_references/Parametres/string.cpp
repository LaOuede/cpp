#include "string.hpp"
#include <iostream>
#include <string>

void byPtr(std::string *str){
	*str += " and ponies";
}

void byConstPtr(std::string const *str) {
	std::cout << *str << std::endl;
}

void byRef(std::string &str) {
	str += " and ponies";
}

void byConstRef(std::string const &str) {
	std::cout << str << std::endl;
}