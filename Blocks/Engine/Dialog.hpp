#ifndef DIALOG_HPP
#define DIALOG_HPP

#include <string>
#ifdef _WIN32
#include <windows.h>
#endif
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Dialog {
public:
    // Constructor and destructor
    Dialog(string, RenderWindow*);
    virtual ~Dialog() {};
    // Dialog functions
    void showError(string);
    void showInfo(string);
private:
    // Dialog private variables
    string title;
#ifdef _WIN32
    HWND handle;                    // Window handle for Windows
    void windiag(string, UINT);     // Windows standard dialog system
#elif __linux__
    void zenity(string, string);    // Unix GTK+ dialog system
#elif __APPLE__ && __MACH__
    void cocoa(string, string);     // Mac OS X Cocoa dialog system
#endif
};

#endif // DIALOG_HPP
