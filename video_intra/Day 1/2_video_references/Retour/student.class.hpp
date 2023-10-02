#ifndef STUDENT_CLASS_H
# define STUDENT_CLASS_H

#include <string>

class Student {

	private:
		std::string _m_login;

	public:
		Student(std::string const &login) : _m_login(login) {}
		
		std::string &getLoginRef() {
			return this->_m_login;
	}

		std::string const &getLoginRefConst() const {
			return this->_m_login;
	}

		std::string *getLoginPtr() {
			return &(this->_m_login);
	}

		std::string const *getLoginPtrConst() const {
			return &(this->_m_login);
	}
};

#endif