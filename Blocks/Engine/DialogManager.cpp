#include "DialogManager.hpp"

DialogManager::DialogManager(string _title, RenderWindow *window) {
    title = _title;
#ifdef _WIN32
    // Set the window handle on Windows
    handle = window->getSystemHandle();
#endif
}

#ifdef _WIN32
void DialogManager::winDialog(string message, UINT flags) {
    MessageBoxA(handle, message.c_str(), title.c_str(), flags);
}

#elif __linux__
void DialogManager::zenity(string message, string type) {
    string cmd("zenity --" + type + " --title=" + title + " --text='"
		+ message + "'");
    // Execute the zenity command
    system(cmd.c_str());
}

#elif __APPLE__ && __MACH__
void DialogManager::cocoa(string icon, string message) {
    string cmd("~/CocoaDialog.app/Contents/MacOS/CocoaDialog ok-msgbox --icon"
		" " + icon + " --text '" + message + "' --title '" + title + "'");
    // Execute the cocoa dialog command
    system(cmd.c_str());
}
#endif

void DialogManager::message(string message) {
#ifdef _WIN32
    winDialog(message, MB_ICONINFORMATION | MB_OK);
#elif __linux__
    zenity(message, "info");
#elif __APPLE__ && __MACH__
    cocoa("info", message);
#endif
}

void DialogManager::error(string message) {
#ifdef _WIN32
    winDialog(message, MB_ICONERROR | MB_OK);
#elif __linux__
    zenity(message, "error");
#elif __APPLE__ && __MACH__
    cocoa("x", message);
#endif
}
