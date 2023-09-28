#ifndef STUDENT_CLASS_H
# define STUDENT_CLASS_H

class Student {

	private:
		std::string _login;

	public:
		Student( std::string login ); // permet de déclarer un constructeur
		~Student( void ); // permet de déclarer un destructeur
};

#endif