/*
FILENAME:		WindowsDialogs.h
AUTHOR:			Salinder Sidhu
DESCRIPTION:	Wrapper for Windows native dialog message boxes. This wrapper is platform dependent!
UPDATE DATE:	10/27/2013
*/

#ifndef WINDOWSDIALOGS_H
#define WINDOWSDIALOGS_H

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