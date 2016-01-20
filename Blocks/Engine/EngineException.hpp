#ifndef ENGINEEXCEPTION_HPP
#define ENGINEEXCEPTION_HPP

#include <string>
#include <exception>
using namespace std;

class EngineException : public exception {
	public:
		EngineException(string _message) {message = _message + "!";};
		virtual ~EngineException() throw() {};
		const char *what() const throw() {return message.c_str();};
	private:
		string message;
};

#endif // ENGINEEXCEPTION_HPP
