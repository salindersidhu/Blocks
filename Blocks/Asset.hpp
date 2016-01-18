#ifndef ASSET_HPP
#define ASSET_HPP

#include <string>
using namespace std;

class Asset {
    public:
        string getName();   // Return the name of the Asset
    private:
        string name;        // The name of the Asset
};

#endif // ASSET_HPP
