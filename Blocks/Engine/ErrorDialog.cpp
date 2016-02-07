#include "ErrorDialog.hpp"

ErrorDialog::ErrorDialog(string _title, RenderWindow *window) {
    title = _title;
#ifdef _WIN32
    // Set the window handle on Windows
    handle = window->getSystemHandle();
#endif
}

#ifdef _WIN32
void ErrorDialog::windiag(string message, UINT flags) {
    MessageBoxA(handle, message.c_str(), title.c_str(), flags);
}

#elif __linux__
void ErrorDialog::zenity(string message, string type) {
    string cmd("zenity --" + type + " --title=" + title + " --text='" +
        message + "'");
    // Execute the zenity command
    system(cmd.c_str());
}

#elif __APPLE__ && __MACH__
void ErrorDialog::cocoa(string message, string icon) {
    string cmd("~/CocoaDialog.app/Contents/MacOS/CocoaDialog ok-msgbox --icon"
        " " + icon + " --text '" + message + "' --title '" + title + "'");
    // Execute the cocoa dialog command
    system(cmd.c_str());
}
#endif

void ErrorDialog::showMessage(string message) {
#ifdef _WIN32
    windiag(message, MB_ICONERROR | MB_OK);
#elif __linux__
    zenity(message, "error");
#elif __APPLE__ && __MACH__
    cocoa(message, "x");
#endif
}
