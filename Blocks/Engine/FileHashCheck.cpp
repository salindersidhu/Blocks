#include "FileHashCheck.hpp"

bool FileHashCheck::isHashMatch(string fileName, string fileHash) {
    // Open file for reading in binary mode
    ifstream file;
    file.open(fileName, ios::in | ios::binary);
    if (file.is_open()) {
        // Obtain the file's starting and ending positions in memory
        streampos start = file.tellg();
        file.seekg(0, ios::end);
        streampos end = file.tellg();
        file.seekg(0, ios::beg);
        // Create a vector to hold the file's binary content
        vector<char> contents;
        contents.resize(static_cast<size_t>(end - start));
        // Read the contents of the file in binary mode into contents
        file.read(&contents[0], contents.size());
        file.close();
        // Generate SHA256 data from the file's contents
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, &contents[0], contents.size());
        SHA256_Final(hash, &sha256);
        // Generate the SHA256 hash string
        stringstream result;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            result << hex << setw(2) << setfill('0') << (int)hash[i];
        }
        // Return the result of the hash matching
        return result.str() == fileHash;
    } else {
        // File pointer does not exist, return false
        return false;
    }
}
