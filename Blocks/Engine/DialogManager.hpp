#ifndef DIALOGMANAGER_HPP
#define DIALOGMANAGER_HPP

#include <string>
#ifdef _WIN32
#include <windows.h>
#endif
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class DialogManager {
    public:
        // Constructor and destructor
        DialogManager(string, RenderWindow*);
        virtual ~DialogManager() {};
        // Dialog functions
        void message(string);
        void error(string);
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

#endif // DIALOGMANAGER_HPP
