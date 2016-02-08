#include "Dialog.hpp"

Dialog::Dialog(string _title, RenderWindow *window) {
    // Set instance variables
    title = _title;
#ifdef _WIN32
    // Set the window handle on Windows
    handle = window->getSystemHandle();
#endif
}

#ifdef _WIN32
void Dialog::windiag(string message, UINT flags) {
    MessageBoxA(handle, message.c_str(), title.c_str(), flags);
}

#elif __linux__
void Dialog::zenity(string message, string type) {
    // Create zenity command string
    string cmd("zenity --" + type + " --title=" + title + " --text='" +
        message + "'");
    // Execute the zenity command
    system(cmd.c_str());
}

#elif __APPLE__ && __MACH__
void Dialog::cocoa(string message, string icon) {
    // Create cocoa command string
    string cmd("~/CocoaDialog.app/Contents/MacOS/CocoaDialog ok-msgbox --icon"
        " " + icon + " --text '" + message + "' --title '" + title + "'");
    // Execute the cocoa dialog command
    system(cmd.c_str());
}
#endif

void Dialog::showError(string message) {
#ifdef _WIN32
    windiag(message, MB_ICONERROR | MB_OK);
#elif __linux__
    zenity(message, "error");
#elif __APPLE__ && __MACH__
    cocoa(message, "x");
#endif
}

void Dialog::showInfo(string message) {
#ifdef _WIN32
    windiag(message, MB_ICONINFORMATION | MB_OK);
#elif __linux__
    zenity(message, "info");
#elif __APPLE__ && __MACH__
    cocoa(message, "info");
#endif
}
