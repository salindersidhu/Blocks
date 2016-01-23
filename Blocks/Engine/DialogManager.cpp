#include "DialogManager.hpp"

DialogManager::DialogManager(string _title, RenderWindow *window) {
    title = _title;
#ifdef _WIN32
    // Set the window handle on Windows
    handle = window->getSystemHandle();
#endif
}

#ifdef _WIN32
void DialogManager::winDialog(string msg, UINT flags) {
    MessageBoxA(handle, msg.c_str(), title.c_str(), flags);
}

#elif __linux__
void DialogManager::zenity(string m, string t) {
    string cmd("zenity --" + t + " --title=" + title + " --text='" + m + "'");
    // Execute the zenity command
    system(cmd.c_str());
}
#endif

void DialogManager::message(string message) {
#ifdef _WIN32
    winDialog(message, MB_ICONINFORMATION | MB_OK);
#elif __linux__
    zenity(message, "info");
#endif
}

void DialogManager::error(string message) {
#ifdef _WIN32
    winDialog(message, MB_ICONERROR | MB_OK);
#elif __linux__
    zenity(message, "error");
#endif
}
