#include "PhysfsStream.hpp"

PhyfsStream::~PhyfsStream() {
	// Close the stream when object is deleted
	close();
}

bool PhyfsStream::isOpen() {
	// Return if stream is open
	return (file != NULL);
}

bool PhyfsStream::open(const string *fileName) {
	// Close the stream and then open the stream for reading
	close();
	file = PHYSFS_openRead(fileName->c_str());
	return isOpen();
}

void PhyfsStream::close() {
	// Close the stream
	if (isOpen()) {
		PHYSFS_close(file);
		file = NULL;
	}
}

Int64 PhyfsStream::read(void *data, Int64 size) {
	// Read data from the stream
	if (!isOpen()) {
		// Return -1 if input stream is not open
		return -1;
	}
	return PHYSFS_read(file, data, 1, static_cast<PHYSFS_uint32>(size));
}

Int64 PhyfsStream::seek(Int64 position) {
	// Change the current reading position
	if (!isOpen()) {
		// Return -1 if input stream is not open
		return -1;
	}
	if (PHYSFS_seek(file, position)) {
		return tell();
	} else {
		return -1;
	}
}

Int64 PhyfsStream::tell() {
	// Get the current reading position in the stream
	if (!isOpen()) {
		// Return -1 if input stream is not open
		return -1;
	}
	return PHYSFS_tell(file);
}

Int64 PhyfsStream::getSize() {
	// Return the size of the stream
	if (!isOpen()) {
		// Return -1 if input stream is not open
		return -1;
	}
	return PHYSFS_fileLength(file);
}
