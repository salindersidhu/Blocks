#ifndef COREOBJECT_HPP
#define COREOBJECT_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "../../Engine/SaveObject.hpp"
#include "../../Engine/GameObject.hpp"
#include "../../Engine/ResourceManager.hpp"
using namespace sf;
using namespace std;

class CoreObject : public GameObject {
    public:
        // Destructor
        virtual ~CoreObject() {};
        // CoreObject functions
        void centerText(Text*, float, float, float, float);
        void centerText(Text*, float, float);
};

#endif // COREOBJECT_HPP
