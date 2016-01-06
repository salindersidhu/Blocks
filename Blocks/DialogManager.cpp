#include "DialogManager.hpp"

DialogManager::DialogManager(string title, HWND handle) {
	dialogTitle = title;
    windowHandle = handle;
}

void DialogManager::message(string message) {
    #ifdef _WIN32
        MessageBoxW(windowHandle, message.c_str(), dialogTitle.c_str(), MB_ICONERROR | MB_OK);
    #elif __linux__
    #endif
}

void DialogManager::error(string message) {
    #ifdef _WIN32
	   MessageBoxW(windowHandle, message.c_str(), dialogTitle.c_str(), MB_ICONINFORMATION | MB_OK);
    #elif __linux__
    #endif
}
