#ifndef DIALOGMANAGER_HPP
#define DIALOGMANAGER_HPP

#include <string>
#ifdef _WIN32
#include <windows.h>
#elif __linux__
#include <stdio.h>
#include <stdlib.h>
#endif
using namespace std;

class DialogManager {
	public:
        // Constructor and destructor
#ifdef _WIN32
		DialogManager(string, HWND);
#elif __linux__
		DialogManager(string);
#endif
		virtual ~DialogManager() {};
		void message(string);
		void error(string);
	private:
		string dialogTitle;
#ifdef _WIN32
		HWND windowHandle;
#endif
};

#endif
