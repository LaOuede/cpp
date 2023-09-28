#ifndef STUDENT_CLASS_H
# define STUDENT_CLASS_H

#include <string>

class Student {

	private:
		std::string _login;

	public:
		Student(std::string const &login) : _login(login) {}
		
		std::string &getLoginRef() {
			return this->_login;
	}

		std::string const &getLoginRefConst() const {
			return this->_login;
	}

		std::string *getLoginPtr() {
			return &(this->_login);
	}

		std::string const *getLoginPtrConst() const {
			return &(this->_login);
	}
};

#endif