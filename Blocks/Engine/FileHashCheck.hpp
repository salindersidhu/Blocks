#ifndef FILEHASHCHECK_HPP
#define FILEHASHCHECK_HPP

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <openssl/sha.h>
using namespace std;

class FileHashCheck {
public:
    // Constructor and destructor
    FileHashCheck() {};
    virtual ~FileHashCheck() {};
    // FileHashCheck functions
    bool isHashMatch(string, string);
};

#endif // FILEHASHCHECK_HPP
