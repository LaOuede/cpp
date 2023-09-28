#include <iostream>
#include "Student.class.hpp"

int main() {
	Student bob = Student("bfoobar");
	Student *jim = new Student("jfoobar");
	delete jim; // jim is destroyed;
	return 0; // bob is destroyed
}