#ifndef TEXTASSET_HPP
#define TEXTASSET_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "Asset.hpp"
using namespace sf;
using namespace std;

class TextAsset : public Asset {
    public:
        // Constructor and destructor
        TextAsset(string, Font);
		virtual ~TextAsset() {};
        // Get asset attribute functions
        Text getText();
        // Configure asset functions
        void setCentered(float, float);
        void setCentered(float, float, float, float);
        // Rendering asset function
        void draw(RenderWindow*);
    private:
        Text text;  // The Text object
};

#endif // TEXTASSET_HPP