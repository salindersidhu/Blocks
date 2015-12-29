#ifndef WINDOWSDIALOGS_HPP
#define WINDOWSDIALOGS_HPP

#include <string>
#include <Windows.h>
using namespace std;

class WindowsDialogs {
	public:
		WindowsDialogs(HWND, string); // Constructor
		virtual ~WindowsDialogs() {}; // Destructor
		void showErrorDialog(string);
		void showInfoDialog(string);
	private:
		HWND windowHandle;
		string dialogTitle;
};

#endif