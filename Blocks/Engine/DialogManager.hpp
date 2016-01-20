#ifndef DIALOGMANAGER_HPP
#define DIALOGMANAGER_HPP

#include <string>
#include <SFML/Graphics.hpp>
#ifdef _WIN32
#include <windows.h>
#elif __linux__
#include <stdio.h>
#include <stdlib.h>
#endif
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
        // Unix zenity GTK+ dialog system
        void zenityCommand(string, string);
#endif
};

#endif // DIALOGMANAGER_HPP
