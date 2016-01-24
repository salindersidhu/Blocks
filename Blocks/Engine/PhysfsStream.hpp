#ifndef PHYSFSSTREAM_HPP
#define PHYSFSSTREAM_HPP

#include <string>
#include <iostream>
#include <physfs.h>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class PhyfsStream : public InputStream {
	public:
        // Constructor and destructor
		PhyfsStream() {};
		virtual ~PhyfsStream();
		// PhysfsStream functions
		bool isOpen();
		bool open(const string*);
		void close();
		virtual Int64 read(void*, Int64);
	    virtual Int64 seek(Int64);
	    virtual Int64 tell();
	    virtual Int64 getSize();
	private:
		// PhysfsStream variables
		PHYSFS_File* file;
};

#endif // PHYSFSSTREAM_HPP
