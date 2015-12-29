#include "WindowsDialogs.hpp"

WindowsDialogs::WindowsDialogs(HWND handle, string title) {
	windowHandle = handle;
	dialogTitle = title;
}

void WindowsDialogs::showErrorDialog(string errorMessage) {
	MessageBoxA(windowHandle, errorMessage.c_str(), dialogTitle.c_str(), MB_ICONERROR | MB_OK);
}

void WindowsDialogs::showInfoDialog(string infoMessage) {
	MessageBoxA(windowHandle, infoMessage.c_str(), dialogTitle.c_str(), MB_ICONINFORMATION | MB_OK);
}