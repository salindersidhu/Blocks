#ifndef GAME_HPP
#define GAME_HPP

#include <map>
#include <vector>
#include <SFML/Graphics.hpp>
#include "LevelObject.hpp"
#include "DialogManager.hpp"
using namespace sf;
using namespace std;

class GameException : public exception {
    public:
        GameException(string _message) {message = _message + "!";};
        virtual ~GameException() throw() {};
        const char *what() const throw() {return message.c_str();};
    private:
        string message;
};

class Game {
    public:
        // Constructor and destructor
        Game(string, int, int, int);
        virtual ~Game() {};
        // Game attribute functions
        RenderWindow* getWindow();
        // Game functions
        void addLevel(LevelObject*);
        void runLoop();
    private:
        // Game variables
        int currentLevel;
        RenderWindow *window;
        DialogManager *dialogMan;
        vector<LevelObject*> levels;
        // Game functions
        void processLevelComplete();
        void checkLevelExist();
};

#endif // GAME_HPP
