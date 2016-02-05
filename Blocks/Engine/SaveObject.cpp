#include "SaveObject.hpp"

void SaveObject::addData(string key, string value) {
    // Add a key-value pair to the save data map
    saveDataMap[key] = value;
}

void SaveObject::clearData(string key) {
    // Delete a specific key-value
    saveDataMap.erase(key);
}

void SaveObject::clearAll() {
    // Clear the entire save data map
    saveDataMap.clear();
}

string SaveObject::getData(string key) {
    // Return the value of the corresponding key from the save data map
    return saveDataMap[key];
}
