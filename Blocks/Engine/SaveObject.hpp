#ifndef SAVEOBJECT_HPP
#define SAVEOBJECT_HPP

#include <map>
#include <string>
using namespace std;

class SaveObject {
    public:
        // Destructor
        virtual ~SaveObject() {};
        // SaveObject functions
        void addData(string, string);
        void clearData(string);
        void clearAll();
        string getData(string);
    private:
        // SaveObject private variables
        map<string, string> saveDataMap;
};

#endif // SAVEOBJECT_HPP
