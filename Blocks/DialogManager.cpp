#include "DialogManager.hpp"

#ifdef _WIN32
	DialogManager::DialogManager(string title, HWND handle) {
		dialogTitle = title;
		windowHandle = handle;
	}
#elif __linux__
	DialogManager::DialogManager(string title) {
		dialogTitle = title;
	}
#endif

void DialogManager::message(string message) {
    #ifdef _WIN32
		MessageBoxA(windowHandle, message.c_str(), dialogTitle.c_str(), MB_ICONINFORMATION | MB_OK);
    #elif __linux__
        system(("zenity --info --title=" + dialogTitle + " --text=" + message).c_str());
    #endif
}

void DialogManager::error(string message) {
    #ifdef _WIN32
		MessageBoxA(windowHandle, message.c_str(), dialogTitle.c_str(), MB_ICONERROR | MB_OK);
    #elif __linux__
        system(("zenity --error --title=" + dialogTitle + " --text=" + message).c_str());
    #endif
}
