#include "PhyfsStream.hpp"

PhyfsStream::~PhyfsStream() {

	close();
}

bool PhyfsStream::isOpen() {

	return (file != NULL);
}

bool PhyfsStream::open(const string *fileName) {

	close();
	file = PHYSFS_openRead(fileName->c_str());
	return isOpen();
}

void PhyfsStream::close() {

	if (isOpen()) {
		PHYSFS_close(file);
		file = NULL;
	}
}

sf::Int64 PhyfsStream::read(void *data, sf::Int64 size) {

	if (!isOpen()) {
		return -1;
	}
	return PHYSFS_read(file, data, 1, static_cast<PHYSFS_uint32>(size));
}

sf::Int64 PhyfsStream::seek(sf::Int64 position) {

	if (!isOpen()) {
		return -1;
	}

	if (PHYSFS_seek(file, position)) {
		return tell();
	} else {
		return -1;
	}
}

sf::Int64 PhyfsStream::tell() {

	if (!isOpen()) {
		return -1;
	}
	return PHYSFS_tell(file);
}

sf::Int64 PhyfsStream::getSize() {

	if (!isOpen()) {
		return -1;
	}
	return PHYSFS_fileLength(file);
}