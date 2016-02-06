#ifndef ERRORDIALOG_HPP
#define ERRORDIALOG_HPP

#include <string>
#ifdef _WIN32
#include <windows.h>
#endif
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class ErrorDialog {
    public:
        // Constructor and destructor
        ErrorDialog(string, RenderWindow*);
        virtual ~ErrorDialog() {};
        // ErrorDialog functions
        void showMessage(string);
    private:
        string title;
#ifdef _WIN32
        // window handle for Windows OSes
        HWND handle;
        // Windows dialog system
        void winDialog(string, UINT);
#elif __linux__
        // Linux zenity GTK+ dialog system
        void zenity(string, string);
#elif __APPLE__ && __MACH__
        // Mac OS X Cocoa dialog system
        void cocoa(string, string);
#endif
};

#endif // ERRORDIALOG_HPP
