#include <iostream>
#include "Student.class.hpp"

int main() {
	Student *students = new Student[7];
	delete [] students; // All students are destroyed;
	return 0; // bob is destroyed
}