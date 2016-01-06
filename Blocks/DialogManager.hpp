#ifndef DIALOGMANAGER_HPP
#define DIALOGMANAGER_HPP

#include <string>
#ifdef _WIN32
    #include <window.h>
#elif __linux__
#endif
using namespace std;

class DialogManager {
	public:
        // Constructor and destructor
		DialogManager(string, HWND);
		virtual ~DialogManager() {};
		void message(string);
		void error(string);
	private:
		string dialogTitle;
};

#endif
