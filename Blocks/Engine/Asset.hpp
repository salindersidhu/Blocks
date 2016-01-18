#ifndef ASSET_HPP
#define ASSET_HPP

#include <string>
#include <exception>
using namespace std;

class AssetException : public exception {
	public:
		AssetException(string _message) {message = _message;};
		virtual ~AssetException() throw() {};
		const char *what() const throw() {return message.c_str();};
	private:
		string message;
};

class Asset {
    protected:
        string name;    // The name of the Asset
};

#endif // ASSET_HPP
