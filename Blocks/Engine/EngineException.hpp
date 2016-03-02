#ifndef ENGINEEXCEPTION_HPP
#define ENGINEEXCEPTION_HPP

#include <string>
#include <exception>
using namespace std;

class EngineException : public exception {
public:
	// Constructor and destructor
	EngineException(string _message) {message = _message + "!";};
	virtual ~EngineException() throw() {};
	// EngineException functions
	const char *what() const throw() {return message.c_str();};
private:
	// EngineException private variables
	string message;
};

#endif // ENGINEEXCEPTION_HPP
