#ifndef PHYFSSTREAM_HPP
#define PHYFSSTREAM_HPP

#include <string>
#include <iostream>
#include <PHYSFS\physfs.h>
#include <SFML\Graphics.hpp>
using namespace std;

class PhyfsStream : public sf::InputStream {
	public:
		PhyfsStream() {}; // Constructor
		virtual ~PhyfsStream(); // Destructor
		bool isOpen();
		bool open(const string*);
		void close();
		virtual sf::Int64 read(void*, sf::Int64);
	    virtual sf::Int64 seek(sf::Int64);
	    virtual sf::Int64 tell();
	    virtual sf::Int64 getSize();
	private:
		PHYSFS_File* file;
};

#endif
